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

void insert_sort(int arr[], int len){
	int key;
	int i, j;

	for(i = 1; i < len; i++){
		key = arr[i];
		j = i-1;

		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}

}

int main(int argc, char *argv[]){
	int array[10] = {0};

	init_array(array);
	printf("=========== the original array is =============\n");
	print_array(array);

	insert_sort(array, MAX);
	printf("=========== after insert_sort, array is =============\n");
	print_array(array);

	return 0;
}
