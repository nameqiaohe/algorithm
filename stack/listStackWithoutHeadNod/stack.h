#ifndef STACK_H
#define STACK_H

typedef struct Node{
    int data;

    struct Node *next;
}Node;

typedef struct Node *Stack;

Stack initStack();

Stack pushStack(Stack stack, int data);

Stack popStack(Stack stack);

int isEmptyStack(Stack stack);

int getStackTop(Stack stack);

Stack destoryStack(Stack stack);

void displayStack(Stack stack);

#endif