/*####################################################
# File Name: merge_sort.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-25 16:51:24
# Last Modified: 2017-05-25 18:05:47
####################################################*/
#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int len){
	int i = 0;
	for(i; i < len; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
	}      
}

void merge(int a[], int begin, int mid, int end, int temp[]){
	printf("begin = %d, mid = %d, end = %d\n", begin, mid, end);

	int left_begin = begin, left_end = mid;
	int right_begin = mid + 1, right_end = end;

	int i = 0;

	while(left_begin <= left_end && right_begin <= right_end){
		if(a[left_begin] <= a[right_begin]){
			temp[i++] = a[left_begin++];
		}else{
			temp[i++] = a[right_begin++];
		}
	}

	while(left_begin <= left_end){
		temp[i++] = a[left_begin++];
	}

	while(right_begin <= right_end){
		temp[i++] = a[right_begin++];
	}

	print_array(temp, i);

	int j = 0;
	for(j = 0; j < i; j++){
		a[begin + j] = temp[j];
	}
}

void merge_sort(int a[], int begin, int end, int temp[]){
	if(end - begin <= 1){
		return;
	}

	int mid = (begin + end)/2;

	merge_sort(a, begin, mid, temp);
	merge_sort(a, mid+1, end, temp);

	merge(a, begin, mid, end, temp);

	printf("==================================\n");

	return;
}

void merge_sort_enter(int a[], int len){
	int *temp = (int *)malloc(len * sizeof(int));
	if(temp == NULL){
		return;
	}

	merge_sort(a, 0, len - 1, temp);

	free(temp);

	return;
}

int main(int argc, char *argv[]){
	int arr[10] = {10, 20, 12, 6, 8, 5, 9, 17, 2, 11};

	merge_sort_enter(arr, 10);
	print_array(arr, 10);

	return 0;
}
