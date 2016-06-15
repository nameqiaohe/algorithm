/*####################################################
# File Name: fibonacci.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-15 19:40:40
# Last Modified: 2016-06-15 19:40:40
####################################################*/
#include <stdio.h>

//计算 斐波那切数列的 第x项 的值
int fib_recursion(int num){
	if(num <= 0){
		return 0;
	}

	if(num == 1 || num ==2 || num ==3){
		return num;
	}else{
		return fib_recursion(num-1) + fib_recursion(num-2);
	}
}

//输出 斐波那切数列
void fib(int num){
	if(num <= 0){
		return;
	}

	if(num >= 1){
		printf("1 ");
		int x = 0, y = 1, z = 1;
		while(num > 0){
			printf("%d ", z);
			x = y;
			y = z;
			z = x + y;

			num--;
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	int num = 0;
	printf("enter a number:\n\t");
	scanf("%d", &num);
#if 0
	//call fib_recursion()
	printf("1 ");
	printf("%d ", fib_recursion(num));
#endif
	//call fib()
	fib(num);

	return 0;
}
