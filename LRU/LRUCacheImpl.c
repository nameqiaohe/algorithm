#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <semaphore.h>

#include "LRUCache.h"
#include "LRUCacheImpl.h"

void unix_error(char *msg){
	fprintf(stderr, "%s : %s\n", msg, strerror(errno));
	exit(0);
}

void semInit(sem_t *sem, int shared, unsigned int value){
	if(sem_init(sem, shared, value) < 0){
		unix_error("semInit Error");
	}
}

void operateP(sem_t *sem){
	if(sem_wait(sem) < 0){
		unix_error("operate P Error");
	}
}

void operateV(sem_t *sem){
	if(sem_post(sem) < 0){
		unix_error("operate V Error");
	}
}

static void freeList(LRUCache *cache);

/* LRU 缓存、缓存单元相关接口实现 */
static CacheEntry *newCacheEntry(char *key, char *data){
	CacheEntry *entry = (CacheEntry *)malloc(sizeof(*entry));
	if(entry == NULL){
		perror("malloc entry");
		return NULL;
	}

	memset(entry, 0x00, sizeof(*entry));

	strncpy(entry->key, key, KEY_SIZE);
	strncpy(entry->data, data, VALUE_SIZE);
	semInit( &(entry->entryLock), 0, 1 );

	return entry;
}

static void freeCacheEntry(CacheEntry *entry){
	if(entry == NULL){
		free(entry);
	}
}

int LRUCacheCreate(int capacity, void **cacheParam){
	LRUCache *cache = (LRUCache *)malloc(sizeof(*cache));
	if(cache == NULL){
		perror("malloc cache");
		return -1;
	}

	memset(cache, 0x00, sizeof(*cache));

	cache->cacheCapacity = capacity;
	semInit( &(cache->cacheLock), 0, 1);
	cache->hashMap = malloc(sizeof(CacheEntry *)*capacity);
	if(cache->hashMap == NULL){
		free(cache);
		perror("malloc cache->hashMap");
		return -1;
	}

	memset(cache->hashMap, 0x00, sizeof(CacheEntry *)*capacity);

	*cacheParam = cache;

	return 0;
}

int LRUCacheDestroy(void *cacheParam){
	LRUCache *cache = (LRUCache *)cacheParam;
	if(cache == NULL){
		return 0;
	}

	if(cache->hashMap){
		free(cache->hashMap);
	}

	freeList(cache);
	free(cache);

	return 0;
}

static void removeFromList(LRUCache *cache, CacheEntry *entry){
	if(cache->LRUListSize == 0){
		return;
	}

	if(entry == cache->LRUListHead && entry == cache->LRUListTail){
		operateP( &cache->cacheLock);
		cache->LRUListHead = cache->LRUListTail = NULL;
		operateV( &cache->cacheLock);
	}else if(entry == cache->LRUListHead){
		operateP( &cache->cacheLock);
		cache->LRUListHead = entry->LRUListNext;
		cache->LRUListHead->LRUListPrev = NULL;
		operateV( &cache->cacheLock);
	}else if(entry == cache->LRUListTail){
		operateP( &cache->cacheLock);
		cache->LRUListTail = entry->LRUListPrev;
		cache->LRUListTail->LRUListNext = NULL;
		operateV( &cache->cacheLock);
	}else{
		operateP( &cache->cacheLock);
		entry->LRUListPrev->LRUListNext = entry->LRUListNext;
		entry->LRUListNext->LRUListPrev = entry->LRUListPrev;
		operateV( &cache->cacheLock);
	}

	operateP( &cache->cacheLock);
	cache->LRUListSize--;
	operateV( &cache->cacheLock);
}

static CacheEntry *insertToListHead(LRUCache *cache, CacheEntry *entry){
	CacheEntry *removedEntry = NULL;

	operateP( &cache->cacheLock);
	++cache->LRUListSize;
	operateV( &cache->cacheLock);

	if(cache->LRUListSize > cache->cacheCapacity){
		removedEntry = cache->LRUListTail;

		removeFromList(cache, cache->LRUListTail);
	}

	if(cache->LRUListHead == NULL && cache->LRUListTail == NULL){
		operateP( &cache->cacheLock);
		cache->LRUListHead = cache->LRUListTail = entry;
		operateV( &cache->cacheLock);
	}else{
		operateP( &cache->cacheLock);
		entry->LRUListNext = cache->LRUListHead;
		entry->LRUListPrev = NULL;
		cache->LRUListHead->LRUListPrev = entry;
		cache->LRUListHead->LRUListNext = entry;
		operateV( &cache->cacheLock);
	}

	return removedEntry;
}

static void freeList(LRUCache *cache){
	if(cache->LRUListSize == 0){
		return;
	}

	CacheEntry *entry = cache->LRUListHead;
	while(entry){
		CacheEntry *temp = entry->LRUListNext;
		freeCacheEntry(entry);
		entry = temp;
	}

	cache->LRUListSize = 0;
}

static void updateLRUList(LRUCache *cache, CacheEntry *entry){
	removeFromList(cache, entry);

	insertToListHead(cache, entry);
}

static unsigned int hashKey(LRUCache *cache, char *key){
	unsigned int len = strlen(key);
	unsigned int x = 378551;
	unsigned int y = 63689;

	unsigned int hash = 0;
	unsigned int i = 0;

	for(i = 0; i < len; key++, i++){
		hash = hash * y + (unsigned int)(*key);
		y = y * x;
	}

	return hash % (cache->cacheCapacity);
}

static CacheEntry *getValueFromHashMap(LRUCache *cache, char *key){
	CacheEntry *entry = cache->hashMap[hashKey(cache, key)];

	while(entry){
		if( !strncmp(entry->key, key, KEY_SIZE)){
			break;
		}

		entry = entry->hashListNext;
	}

	return entry;
}

static void insertEntryToHashMap(LRUCache *cache, CacheEntry *entry){
	CacheEntry *tempEntry = cache->hashMap[hashKey(cache, entry->key)];

	operateP( &cache->cacheLock);

	if(tempEntry != NULL){
		entry->hashListNext = tempEntry;
		tempEntry->hashListPrev = entry;
	}

	cache->hashMap[hashKey(cache, entry->key)] = entry;

	operateV( &cache->cacheLock);
}

static void removeEntryFromHashMap(LRUCache *cache, CacheEntry *entry){
	if(entry == NULL || cache == NULL || cache->hashMap == NULL){
		return;
	}

	CacheEntry *tempEntry = cache->hashMap[hashKey(cache, entry->key)];

	while(tempEntry){
		if(tempEntry->key == entry->key){
			if(tempEntry->hashListPrev){
				operateP( &cache->cacheLock);
				tempEntry->hashListPrev->hashListNext = tempEntry->hashListNext;
				operateV( &cache->cacheLock);
			}else{
				operateP( &cache->cacheLock);
				cache->hashMap[hashKey(cache, entry->key)] = tempEntry->hashListNext;
				operateV( &cache->cacheLock);
			}

			if(tempEntry->hashListNext){
				operateP( &cache->cacheLock);
				tempEntry->hashListNext->hashListPrev = tempEntry->hashListPrev;
				operateV( &cache->cacheLock);
			}

			return;
		}

		tempEntry = tempEntry->hashListNext;
	}

}

int LRUCacheSet(void *cacheParam, char *key, char *data){
	LRUCache *cache = (LRUCache *)cacheParam;

	CacheEntry *entry = getValueFromHashMap(cache, key);
	if(entry != NULL){
		operateP( &entry->entryLock);
		strncpy(entry->data, data, VALUE_SIZE);
		operateV( &entry->entryLock);
		updateLRUList(cache, entry);
	}else{
		entry = newCacheEntry(key, data);

		CacheEntry *removedEntry = insertToListHead(cache, entry);
		if(removedEntry != NULL){
			removeEntryFromHashMap(cache, removedEntry);
			freeCacheEntry(removedEntry);
		}

		insertEntryToHashMap(cache, entry);
	}

	return 0;
}

char *LRUCacheGet(void *cacheParam, char *key){
	LRUCache *cache = (LRUCache *)cacheParam;
	
	CacheEntry *entry = getValueFromHashMap(cache, key);
	if(entry != NULL){
		updateLRUList(cache, entry);
		return entry->data;
	}else{
		return NULL;
	}
}

void LRUCachePrint(void *cacheParam){
	LRUCache *cache = (LRUCache *)cacheParam;

	if(cache == NULL || cache->LRUListSize == 0){
		return ;
	}

	fprintf(stdout, "\n>>>>>>>>>>>>>>>>>>>>>>>>\n");
	fprintf(stdout, "cache (key - data) : \n");
	CacheEntry *entry = cache->LRUListHead;
	while(entry){
		fprintf(stdout, "(%s - %s)", entry->key, entry->data);
		entry = entry->LRUListNext;
	}

	fprintf(stdout, "\n>>>>>>>>>>>>>>>>>>>>>>>>\n");
}