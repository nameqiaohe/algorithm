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

void quick_sort(int arr[], int left, int right){
	if(left < right){
		int low = left;
		int high = right;
		int pivot = arr[low];

		while(low < high){
			while(low < high && arr[high] >= pivot)
				high--;
			if(low < high){
				arr[low] = arr[high];
				low++;
			}

			while(low < high && arr[low] <= pivot)
				low++;
			if(low < high){
				arr[high] = arr[low];
				high--;
			}
		}
		arr[low] = pivot;

		quick_sort(arr, left, low-1);
		quick_sort(arr, low+1, right);
	}
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
