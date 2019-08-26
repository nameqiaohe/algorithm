#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Queue initQueue(){
    Queue queue = (Queue)malloc(sizeof(struct queue));
    if(queue == NULL){
        perror("malloc space for queue failed!");
        return NULL;
    }

    queue->head = 0;
    queue->tail = 0;

    queue->currentSize = 0;

    return queue;
}

/*
    返回值：0 - 入队成功， 非 0 - 入队失败；
*/
int pushQueue(Queue queue, int data){
    if(!isFullQueue(queue)){
        printf("Queue is full!\n");
        return 1;
    }

    queue->datas[queue->tail] = data;
    queue->tail = queue->tail%QUEUE_MAX_COUNT + 1;

    queue->currentSize++;

    return 0;
}

int isEmptyQueue(Queue queue){
    // if(queue->head == queue->tail)
    if(queue->currentSize == 0){
        return 0;//空队列
    }else{
        return 1;//非空队列
    }
}

int isFullQueue(Queue queue){
    // if(queue->currentSize == QUEUE_MAX_COUNT){
    if( queue->tail%QUEUE_MAX_COUNT + 1 == queue->head ){
        return 0;   // 队列 已满
    }else{
        return 1;   // 队列 非满
    }
}

int popQueue(Queue queue){
    if(!isEmptyQueue(queue)){
        printf("Queue is empty!\n");
        return INT_MIN;
    }

    int data = queue->datas[queue->head];
    queue->head = queue->head % QUEUE_MAX_COUNT + 1;
    
    queue->currentSize--;

    return data;
}

Queue destoryQueue(Queue queue){
    queue->head = queue->tail = 0;
    queue->currentSize = 0;
    free(queue);
    queue = NULL;

    return queue;
}

void displayQueue(Queue queue){
    if(queue == NULL || !isEmptyQueue(queue)){
        printf("Queue is empty!\n");
        return;
    }

    printf("Display Queue datas:");
    int i = queue->head;
    if(queue->head < queue->tail){
        while(i < queue->tail){
            printf("%d, ", queue->datas[i]);
            i++;
        }
    }else{
        // while(i != (queue->tail % QUEUE_MAX_COUNT + 1)){
        while(i < queue->tail + QUEUE_MAX_COUNT){
            printf("%d, ", queue->datas[i]);
            i++;
        }
    }

    printf("\n");
}