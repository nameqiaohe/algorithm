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

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

Queue pushQueue(Queue queue, TreeNode *data){
    QueueNode *queueNode = (QueueNode *)malloc(sizeof(QueueNode));
    if(queueNode == NULL){
        perror("malloc space for queueNode failed!");
        return NULL;
    }

    queueNode->data = data;
    queueNode->next = NULL;
    
    if(queue->head == NULL){
        queue->head = queueNode;
    }

    if(queue->tail == NULL){
        queue->tail = queueNode;
    }else{
        queue->tail->next = queueNode;
        queue->tail = queueNode;
    }

    return queue;
}

int isEmptyQueue(Queue queue){
    if(queue->head == NULL){
        return 0;//空队列
    }else{
        return 1;//非空队列
    }
}

TreeNode *popQueue(Queue queue){
    TreeNode *data = NULL;
    if(!isEmptyQueue(queue)){
        printf("Queue is empty!\n");
        return data;
    }

    QueueNode *queueNode = queue->head;
    if(queue->head == queue->tail){
        data = queueNode->data;
        free(queueNode);
        queueNode = NULL;

        queue->head = NULL;
        queue->tail = NULL;

        return data;
    }else{
        data = queueNode->data;

        queue->head = queue->head->next;
        free(queueNode);
        queueNode = NULL;

        return data;
    }
}

Queue destoryQueue(Queue queue){
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
    QueueNode *queueNode = queue->head;
    while(queueNode){
        printf("%d, ", queueNode->data->data);
        queueNode = queueNode->next;
    }
    printf("\n");
}