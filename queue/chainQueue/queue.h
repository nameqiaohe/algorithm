#ifndef QUEUE_H
#define QUEUE_H

struct node
{
    int data;
    struct node *next;
};
typedef struct node *Node;

struct queue
{
    Node head;
    Node tail;
};
typedef struct queue *Queue;

Queue initQueue();

int isEmptyQueue(Queue queue);

Queue pushQueue(Queue queue, int data);

int popQueue(Queue queue);

Queue destoryQueue(Queue queue);

void displayQueue(Queue queue);

#endif