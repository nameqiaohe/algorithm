#include <stdio.h>
#include "stack.h"

int main(){
    Stack stack = initStack();

    int i = 0;
    for (i = 4; i < 10; i++)
    {
        stack = pushStack(stack, i);
    }
    displayStack(stack);

    stack = popStack(stack);
    displayStack(stack);

    stack = destoryStack(stack);    

    return 0;
}