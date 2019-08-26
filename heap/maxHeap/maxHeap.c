#include "maxHeap.h"
#include <stdio.h>
#include <stdlib.h>

MaxHeap createMaxHeap(int size){
    MaxHeap heap = (MaxHeap)malloc(sizeof(struct myHeap));
    if(heap == NULL){
        perror("malloc space for heap failed!");
        return heap;
    }

    heap->datas = (int *)malloc(size*sizeof(int));
    heap->capacity = size;
    heap->currentSize = 0;

    return heap;
}

int isFullHeap(MaxHeap heap){
    if(heap->currentSize == heap->capacity){
        return TRUE;
    }else{
        return FALSE;
    }
}

int isEmptyHeap(MaxHeap heap){
    if(heap->currentSize == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void swapData(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void filterUpMaxHeap(MaxHeap heap, int index){
    int curIndex = index;
    int pIndex = (curIndex-1)/2;
    int key = heap->datas[curIndex];

    while(curIndex > 0){
        if(heap->datas[pIndex] >= key){
            break;
        }else{
            heap->datas[curIndex] = heap->datas[pIndex];
            curIndex = pIndex;
            pIndex = (pIndex-1)/2;
        }
    }
    heap->datas[curIndex] = key;
}

int insertMaxHeap(MaxHeap heap, int val){
    if(!isFullHeap(heap)){//如果堆已满，则扩容
        heap = (MaxHeap)realloc(heap, 2*heap->capacity*sizeof(int));
        if(heap == NULL){
            perror("realloc space for heap failed!");
            return FALSE;
        }

        printf("heap's capacity expansion is 2 times the original!\n");
        heap->capacity = heap->capacity*2;
    }

    heap->datas[heap->currentSize] = val;
    filterUpMaxHeap(heap, heap->currentSize);
    heap->currentSize++;

    return TRUE;
}

void filterDownMaxHeap(MaxHeap heap, int startIndex, int endIndex){

}

int deleteMaxHeap(MaxHeap heap){
    if(!isEmptyHeap(heap)){
        perror("Heap is Empty!");
        return FALSE;
    }

    
}