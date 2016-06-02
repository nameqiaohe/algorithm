/*####################################################
# File Name: bubble_sort.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-02 22:41:00
# Last Modified: 2016-06-02 22:41:00
####################################################*/
#include <stdio.h>

#define MAX 10

void init_array(int arr[]){
	printf("input %d numbers\n", MAX);
	int i = 0;
	for(i; i < MAX; i++){
		scanf("%d", &arr[i]);
	}
}

void print_array(int arr[]){
	int i = 0;
	for(i; i < MAX; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void bubble_sort(int arr[]){
	int i = 0, j = 0;
	int temp;

	for(i; i < MAX; i++){
		for(j = 0; j < MAX-i-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(int argc, char *argv[]){
	int array[10] = {0};

	init_array(array);
	printf("=========== the original array is =============\n");
	print_array(array);

	bubble_sort(array);
	printf("=========== after bubble_sort, array is =============\n");
	print_array(array);

	return 0;
}
