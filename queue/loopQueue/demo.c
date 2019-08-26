#include "queue.h"
#include <stdio.h>

int main(){
    Queue queue = initQueue();

    int i = 0;
    for(i = 0; i < 10; ++i){
        pushQueue(queue, i);
    }
    displayQueue(queue);

    int data = popQueue(queue);
    displayQueue(queue);

    queue = destoryQueue(queue);
    displayQueue(queue);

    return 0;
}