#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Stack *createStack(){
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL){
		perror("malloc space for stack error");
		return NULL;
	}

	stack->data = 0;
	stack->next = NULL;
	return stack;
}

void clearStack(Stack *stack){
	while(isStackEmpty(stack)){
		popStack(stack);
	}
	printf("-----Now stack is empty\n");
}

void destoryStack(Stack *stack){
	clearStack(stack);
	free(stack);
	printf("----Now stack is destoryed!\n");
}

/***
	返回值：0 - 空栈，非0 - 非空栈
***/
int isStackEmpty(Stack *stack){
	if(stack->next == NULL){
		return 0;
	}else{
		return 1;
	}
}

/***
	返回值：0 - 入栈成功，非0 - 入栈失败
***/
int pushStack(Stack *stack, int data){
	Stack *temp = (Stack *)malloc(sizeof(Stack));
	if(temp == NULL){
		perror("malloc space for node error");
		return -1;
	}

	temp->data = data;
	temp->next = stack->next;

	stack->next = temp;

	return 0;
}

/***
	返回值：0 - 出栈成功，非0 - 出栈失败
***/
int popStack(Stack *stack){
	if(isStackEmpty(stack) == 0){
		printf("stack is empty\n");
		return -1;
	}

	Stack *temp = stack->next;
	stack->next = temp->next;
	free(temp);
	temp = NULL;

	return 0;
}

/***
	返回值：第一个节点，调用出再通过节点获取到 data
***/
int getStackTop(Stack *stack){
	if(!isStackEmpty(stack)){
		perror("stack is empty");
		return INT_MIN;
	}

	return stack->next->data;
}

void printStack(Stack *stack){
	printf("----Stack elements : ");
	while(isStackEmpty(stack)){
		printf("%d, ", getStackTop(stack));
		stack = stack->next;
	}
	printf("\n");
}