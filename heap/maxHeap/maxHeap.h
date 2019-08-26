#ifndef MY_HEAP_H
#define MY_HEAP_H

#define TRUE 0
#define FALSE 1

#define INIT_SIZE 100

struct myHeap
{
    int *datas;

    int currentSize;
    int capacity;
};

typedef struct myHeap *MaxHeap;

MaxHeap createMaxHeap(int size);

int isFullHeap(MaxHeap heap);

int isEmptyHeap(MaxHeap heap);

// 调整最大堆 - 向上调整
void filterUpMaxHeap(MaxHeap heap, int index);

// 调整最大堆 - 向下调整
void filterDownMaxHeap(MaxHeap heap, int startIndex, int endIndex);

void buildMaxHeap(MaxHeap heap);

int insertMaxHeap(MaxHeap heap, int val);

int deleteMaxHeap(MaxHeap heap);// 删除根节点

int getDataIndex(MaxHeap heap, int val);

void swapData(int *x, int *y);

void displayHeap(MaxHeap heap, char *msg);

int destoryHeap(MaxHeap heap);

#endif