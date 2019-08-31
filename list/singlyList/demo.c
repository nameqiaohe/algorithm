#include "singlyList.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    SinglyList *list = createSinglyList();
    if(list == NULL){
        printf("create list error!\n");
        return -1;
    }

    singlyListAddAtHead(list, 10);

    singlyListAddAtTail(list, 20);

    singlyListAddAtIndex(list, 1, 30);
    displaySinglyList(list);

    singlyListReverse(&list);
    displaySinglyList(list);

    // singlyListDeleteAtIndex(list, 1);
    // displaySinglyList(list);

    // singlyListDeleteAtIndex(list, 1);
    // displaySinglyList(list);

    singlyListFree(list);    

    return 0;
}
