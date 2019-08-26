# C语言实现循环队列

--------------------------

## 1. Queue pushQueue(Queue queue)
    返回值：Queue
        也可以将返回值设为 void，因为其中的操作 就是在操作队列 queue

## 2. Queue destoryQueue(Queue queue)
Queue destoryQueue(Queue queue){    // 加入传入的 queue地址为 0x1002001f0
    queue->head = queue->tail = 0;
    queue->currentSize = 0;
    free(queue);
    queue = NULL;   // 这里将 queue 置为空NULL (0x0)
        // 如果不返回 queue的话，destoryQueue方法之后，访问到的 queue 地址还是 0x1002001f0，但是其中的 head、tail、currentSize属性都为 0.
        // 原因：？？？

    return queue;   // 所以，这里需要将 修改后的 queue带出去
}

