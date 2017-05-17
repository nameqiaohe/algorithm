/*####################################################
# File Name: test.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-17 21:54:14
# Last Modified: 2017-05-17 22:12:09
####################################################*/
#include "min_heap.h"

int main(void){
	int a[] = {80, 40, 30, 60, 90, 70, 10, 50, 20};
	int i, len=LENGTH(a);

	printf("== 依次添加: ");
	for(i=0; i<len; i++){
		printf("%d ", a[i]);
		min_heap_insert(a[i]);
	}

	printf("\n== 最 小 堆: ");
	min_heap_print();

	i=85;
	min_heap_insert(i);
	printf("\n== 添加元素: %d", i);
	printf("\n== 最 小 堆: ");
	min_heap_print();

	i=90;
	min_heap_remove(i);
	printf("\n== 删除元素: %d", i);
	printf("\n== 最 小 堆: ");
	min_heap_print();
	printf("\n");

	return 0;
}
