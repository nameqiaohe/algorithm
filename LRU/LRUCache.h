#ifndef LRU_CACHE_H
#define LRU_CACHE_H

/* 创建LRU缓存 */
int LRUCacheCreate(int capacity, void **LRUCache);

/* 销毁LRU缓存 */
int LRUCacheDestroy(void *LRUCache);

/* 将数据放入LRU缓存中 */
int LRUCacheSet(void *LRUCache, char *key, char *data);

/* 从缓存中获取数据 */
char *LRUCacheGet(void *LRUCache, char *key);

/* 打印缓存中的数据，按照访问时间 从新到旧的顺序输出 */
void LRUCachePrint(void *LRUCache);

#endif //LRU_CACHE_H