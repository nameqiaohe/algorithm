#include "maxHeap.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    MaxHeap heap = createMaxHeap(INIT_SIZE);

    insertMaxHeap(heap, 23);
    displayHeap(heap, "insert");

    insertMaxHeap(heap, 10);
    displayHeap(heap, "insert");

    insertMaxHeap(heap, 12);
    displayHeap(heap, "insert");

    insertMaxHeap(heap, 45);
    displayHeap(heap, "insert");

    insertMaxHeap(heap, 89);
    displayHeap(heap, "insert");

    insertMaxHeap(heap, 9);
    displayHeap(heap, "insert");

    insertMaxHeap(heap, 18);
    displayHeap(heap, "insert");

    deleteMaxHeap(heap);
    displayHeap(heap, "delete");

    destoryHeap(heap);

    return 0;
}
