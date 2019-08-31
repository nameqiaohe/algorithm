#include "singlyList.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

SinglyList *createSinglyList(){
    SinglyList *listNode = (SinglyList *)malloc(sizeof(SinglyList));
    if(listNode == NULL){
        printf("malloc memory for listNode failed!\n");
        return NULL;
    }
    listNode->data = INT_MIN;
    listNode->currentSize = 0;
    listNode->next = NULL;
    return listNode;
}

int singlyListGet(SinglyList *list, int index){
    if(list->currentSize < index || list->currentSize == 0){
        printf("invalid index!\n");
        return -1;
    }
    SinglyList *temp = list;
    int i = 0;
    while(i <= index){
        temp = temp->next;
        i++;
    }
    return temp->data;
}

void singlyListAddAtHead(SinglyList *list, int val){
    if(list->currentSize == 0){
        list->data = val;
        list->currentSize++;

        return;
    }

    SinglyList *listNode = (SinglyList *)malloc(sizeof(SinglyList));
    if(listNode == NULL){
        printf("malloc memory for listNode failed!\n");
        return;
    }

    listNode->data = val;
    listNode->next = list;

    list = listNode;
    list->currentSize++;
}

void singlyListAddAtTail(SinglyList *list, int val){
    if(list->currentSize == 0){
        list->data = val;
        list->currentSize++;

        return;
    }

    SinglyList *node = (SinglyList *)malloc(sizeof(SinglyList));
    if(node == NULL){
        printf("malloc memory for node failed!\n");
        return;
    }
    node->data = val;
    node->next = NULL;

    SinglyList *temp = list;
    int index = 0;
    while(index < list->currentSize-1){
        temp = temp->next;
        index++;
    }
    temp->next = node;
    list->currentSize++;
}

void singlyListAddAtIndex(SinglyList *list, int index, int val){
    if(list->currentSize < index || list->currentSize == 0){
        printf("invalid index!\n");
        return;
    }

    int i = 0;
    SinglyList *node = (SinglyList *)malloc(sizeof(SinglyList));
    if(node == NULL){
        printf("malloc memory for node failed!\n");
        return ;
    }
    node->data = val;
    node->next = NULL;

    SinglyList *temp = list;
    while(i < index-1){
        temp = temp->next;
        i++;
    }
    node->next = temp->next;
    temp->next = node;

    list->currentSize++;
}

void singlyListDeleteAtIndex(SinglyList *list, int index){
    if(list->currentSize == 0 || list->currentSize <= index){
        printf("index is invalid!\n");
        return;
    }

    SinglyList *temp = list;
    int i = 0;
    while(i < index-1){
        temp = temp->next;
        i++;
    }
    SinglyList *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
    deleteNode = NULL;

    list->currentSize--;
}

/***
 * 入参：二级指针
 * 解释：list 指向的地址为 0x345678，经过反转之后，list 指向的地址还是 0x345678，但是此时 list已经是最后一个节点了。
 *      所以需要将 list 指向的地址改为 新的头结点，用二级指针是为了 用入参将新的头结点带出去。
 * 
 *      如果 入参是一级指针，虽然最后 也将新的头结点赋值给了 list，但是这里改变的是 形参 - 入参的副本，没有真正改变入参的指向。
 * 建议：如果不想传入二级指针，则需要修改返回值 为指针，结尾处将 list返回
 * ***/
void singlyListReverse(SinglyList **list){
    if((*list)->currentSize == 0){
        printf("list is empty!\n");
        return;
    }

    int size = (*list)->currentSize;

    SinglyList *prev = NULL;
    SinglyList *cur = *list;
    SinglyList *next = NULL;
    while(cur){
        next = cur->next;

        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *list = prev;
    (*list)->currentSize = size;
}

void singlyListFree(SinglyList *list){
    SinglyList *temp = NULL;
    while(list){
        temp = list;

        list = list->next;
        free(temp);
        temp = NULL;
    }
}

void displaySinglyList(SinglyList *list){
    if(list->currentSize == 0){
        printf("list is empty!\n");
        return;
    }

    SinglyList *temp = list;
    while (temp)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}