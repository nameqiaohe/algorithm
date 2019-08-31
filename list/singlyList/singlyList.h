#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

struct singlyList
{
    int data;

    int currentSize;

    struct singlyList *next;
}singlyList;
typedef struct singlyList SinglyList;

SinglyList *createSinglyList();

int singlyListGet(SinglyList *list, int index);

void singlyListAddAtHead(SinglyList *list, int val);

void singlyListAddAtTail(SinglyList *list, int val);

void singlyListAddAtIndex(SinglyList *list, int index, int val);

void singlyListDeleteAtIndex(SinglyList *list, int index);

void singlyListReverse(SinglyList **list);

void singlyListFree(SinglyList *list);

void displaySinglyList(SinglyList *list);

#endif