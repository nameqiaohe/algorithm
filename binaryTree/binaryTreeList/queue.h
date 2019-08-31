#ifndef QUEUE_H
#define QUEUE_H

#include "binary_tree.h"

struct queue_node
{
    TreeNode *data;
    struct queue_node *next;
};
typedef struct queue_node QueueNode;

struct queue
{
    QueueNode *head;
    QueueNode *tail;
};
typedef struct queue *Queue;

Queue initQueue();

int isEmptyQueue(Queue queue);

Queue pushQueue(Queue queue, TreeNode *data);

TreeNode *popQueue(Queue queue);

Queue destoryQueue(Queue queue);

void displayQueue(Queue queue);

#endif