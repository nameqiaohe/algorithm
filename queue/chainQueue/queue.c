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

Queue pushQueue(Queue queue, int data){
    Node node = (Node)malloc(sizeof(struct node));
    if(node == NULL){
        perror("malloc space for node failed!");
        return NULL;
    }

    node->data = data;
    node->next = NULL;
    
    if(queue->head == NULL){
        queue->head = node;
    }

    if(queue->tail == NULL){
        queue->tail = node;
    }else{
        queue->tail->next = node;
        queue->tail = node;
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

int popQueue(Queue queue){
    if(!isEmptyQueue(queue)){
        printf("Queue is empty!\n");
        return INT_MIN;
    }

    int data;
    Node node = queue->head;
    if(queue->head == queue->tail){
        data = node->data;
        free(node);
        node = NULL;

        queue->head = NULL;
        queue->tail = NULL;

        return data;
    }else{
        data = node->data;

        queue->head = queue->head->next;
        free(node);
        node = NULL;

        return data;
    }
}

Queue destoryQueue(Queue queue){
    if(!isEmptyQueue(queue)){
        printf("Queue is empty!\n");
        
        free(queue);
        queue = NULL;
        return queue;
    }

    Node node = queue->head;
    while(node != NULL){
        queue->head = queue->head->next;

        free(node);

        node = queue->head;
    }

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
    Node node = queue->head;
    while(node){
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("\n");
}