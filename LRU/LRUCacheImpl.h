#ifndef LRU_CACHE_IMPL_H
#define LRU_CACHE_IMPL_H

#include <semaphore.h>

#define KEY_SIZE 50
#define VALUE_SIZE 100

/* 定义 LRU 缓存的 缓存单元 */
typedef struct CacheEntry{
	char key[KEY_SIZE];
	char data[VALUE_SIZE];

	sem_t entryLock;

	struct CacheEntry *hashListPrev;
	struct CacheEntry *hashListNext;

	struct CacheEntry *LRUListPrev;
	struct CacheEntry *LRUListNext;
}CacheEntry;

/* 定义 LRU 缓存 */
typedef struct LRUCache{
	sem_t cacheLock;

	int cacheCapacity;
	int LRUListSize;

	CacheEntry **hashMap;

	CacheEntry *LRUListHead;
	CacheEntry *LRUListTail;
}LRUCache;

#endif //LRU_CACHE_IMPL_H