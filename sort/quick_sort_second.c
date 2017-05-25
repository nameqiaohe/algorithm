/*####################################################
# File Name: bubble_sort.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-02 22:41:00
# Last Modified: 2017-05-25 16:18:17
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

void swap(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void quick_sort(int arr[], int begin, int end){
	if(begin >= end)
		return;

		int left = begin;
		int right = end;
		int pivot_value = arr[left];

		while(left < right){
			if(arr[left + 1] < pivot_value){
				arr[left] = arr[left+1];
				left++;
			}else{
				swap(&arr[left+1], &arr[right]);
				right--;
			}
		}
		arr[left] = pivot_value;

		quick_sort(arr, begin, left-1);
		quick_sort(arr, left+1, end);
}

int main(int argc, char *argv[]){
	int array[10] = {0};

	init_array(array);
	printf("=========== the original array is =============\n");
	print_array(array);

	quick_sort(array, 0, MAX-1);
	printf("=========== after quick_sort, array is =============\n");
	print_array(array);

	return 0;
}
