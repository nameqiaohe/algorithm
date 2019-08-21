#include "stack.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

Stack initStack(){
    return NULL;
}

Stack pushStack(Stack stack, int data){
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL){
        perror("malloc space for node failed!");
        return NULL;
    }

    node->data = data;
    node->next = stack;

    stack = node;

    return stack;
}

Stack popStack(Stack stack){
    if(!isEmptyStack(stack)){
        return NULL;
    }

    Node *node = stack;
    stack = stack->next;

    free(node);
    node = NULL;

    return stack;
}

/*
    返回值：0 - 空栈，非0 - 非空栈
*/
int isEmptyStack(Stack stack){
    if(stack == NULL){
        return 0;
    }else{
        return -1;
    }
}

int getStackTop(Stack stack){
    if(!isEmptyStack(stack)){
        return INT_MIN;
    }else{
        return stack->data;
    }
}

Stack destoryStack(Stack stack){
    Node *node = stack;
    while(isEmptyStack(stack)){
        stack = stack->next;

        free(node);
        node = stack;
    }

    printf("Stack is destoryed!\n");

    return stack;
}

void displayStack(Stack stack){
    printf("Display Stack:");
    Node *node = stack;
    while(isEmptyStack(node)){
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("\n");
}