#include "queue.h"
#include <stdio.h>

int main(){
    Queue queue = initQueue();

    int i = 0;
    for(i; i < 10; ++i){
        queue = pushQueue(queue, i);
    }
    displayQueue(queue);

    int data = popQueue(queue);
    displayQueue(queue);

    queue = destoryQueue(queue);
    displayQueue(queue);

    return 0;
}