/*####################################################
# File Name: main.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-25 22:12:00
# Last Modified: 2017-05-25 22:22:49
####################################################*/
#include "binary_tree.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	node *root = NULL;
	int data;
	int count;
	printf("enter a number:\n");
	scanf("%d", &count);

	printf("enter %d numbers:\n", count);
	int i = 0;
	for(i = 0; i <count; i++){
		scanf("%d", &data);
		tree_insert(&root, data);
	}

	node *item = tree_find(root, 13);
	if(item != NULL){
		printf("found it, item->data = %d\n", item->data);
	}

	printf("mid_traversal : ");
	mid_traversal(root);
	printf("\n");

	if(tree_delete(&root, 30)){
		printf("after delete, mid_traversal : ");
		mid_traversal(root);
	}
	printf("\n");
	
	return 0;
}
