#ifndef STACK_H
#define STACK_H

typedef struct Node
{
	int data;

	struct Node *next;
}Stack;

Stack *createStack();

void clearStack(Stack *stack);

void destoryStack(Stack *stack);

int isStackEmpty(Stack *stack);

int pushStack(Stack *stack, int data);

int popStack(Stack *stack);

int getStackTop(Stack *stack);

void printStack(Stack *stack);

#endif