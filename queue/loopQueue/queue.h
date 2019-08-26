#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_MAX_COUNT 20

struct queue
{
    int head;//队列头索引
    int tail;//队列尾索引

    int datas[QUEUE_MAX_COUNT];

    int currentSize;    // 当前存储元素个数
};
typedef struct queue *Queue;

Queue initQueue();

int isEmptyQueue(Queue queue);

int isFullQueue(Queue queue);

int pushQueue(Queue queue, int data);

int popQueue(Queue queue);

Queue destoryQueue(Queue queue);

void displayQueue(Queue queue);

#endif