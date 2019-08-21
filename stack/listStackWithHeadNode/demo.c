#include "stack.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Stack *stack = createStack();

	printf("====pushStack\n");
	pushStack(stack, 5);
	printStack(stack);

	printf("====pushStack\n");
	pushStack(stack, 6);
	printStack(stack);

	printf("====pushStack\n");
	pushStack(stack, 7);
	printStack(stack);

	printf("====popStack\n");
	popStack(stack);
	printStack(stack);

	printf("====popStack\n");
	popStack(stack);
	printStack(stack);

	printf("====clearStack\n");
	clearStack(stack);
	printStack(stack);

	printf("====destoryStack\n");
	destoryStack(stack);

	return 0;
}