/*####################################################
# File Name: test.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-17 21:54:14
# Last Modified: 2017-05-17 22:00:19
####################################################*/
#include "max_heap.h"

int main(void){
	int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
	int i, len=LENGTH(a);

	printf("== 依次添加: ");
	for(i=0; i<len; i++){
		printf("%d ", a[i]);
		max_heap_insert(a[i]);
	}

	printf("\n== 最 大 堆: ");
	max_heap_print();

	i=85;
	max_heap_insert(i);
	printf("\n== 添加元素: %d", i);
	printf("\n== 最 大 堆: ");
	max_heap_print();

	i=90;
	max_heap_remove(i);
	printf("\n== 删除元素: %d", i);
	printf("\n== 最 大 堆: ");
	max_heap_print();
	printf("\n");

	return 0;
}
