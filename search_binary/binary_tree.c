/*####################################################
# File Name: binary_tree.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-25 21:23:40
# Last Modified: 2017-05-25 22:24:23
####################################################*/
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int tree_insert(node **root, elem_type key){
	/* 构造节点 */
	node *item = (node *)malloc(sizeof(node));
	if(item == NULL){
		perror("malloc memory for item error");
		return 0;
	}
	item->data = key;
	item->left_child = NULL;
	item->right_child = NULL;
	item->parent = NULL;

	if(*root == NULL){
		*root = item;
		return 1;//插入节点成功
	}

	node *x = *root;
	node *y = x;//用来记录 x 的值
	while(x != NULL){//不为空 或者 没有到尾部
		y = x;
		if(x->data == key){//已存在该节点
			return 0;
		}else if(x->data < key){
			x = x->right_child;
		}else{
			x = x->left_child;
		}
	}

	if(y->data > key){
		y->left_child = item;
	}else{
		y->right_child = item;
	}
	item->parent = y;
	return 1;
}

void mid_traversal(node *root){
	if(root != NULL){
		mid_traversal(root->left_child);
		printf("root->data = %d, ", root->data);
		mid_traversal(root->right_child);
	}
}

node *tree_find(node *root, elem_type key){
	while(root != NULL && root->data != key){
		if(root->data > key){
			root = root->left_child;
		}else{
			root = root->right_child;
		}
	}
	return root;
}

/* 替换：将 x 替换为 y */
void replace_node(node **root, node *x, node *y){
	if(x->parent == NULL){
		*root = y;
	}else if(x == x->parent->right_child){// x 为右孩子
		x->parent->right_child = y;
	}else{
		x->parent->left_child = y;
	}

	if(y != NULL){
		y->parent = x->parent;
	}
}

int tree_delete(node **root, elem_type key){
	node *item = tree_find(*root, key);
	if(item == NULL){
		perror("not found");
		return 0;
	}

	if(item->left_child != NULL && item->right_child != NULL){//该节点有两个孩子
		node *y = item->right_child;
		while(y->left_child != NULL){
			y = y->left_child;
		}

		if(y != item->right_child){//说明 y 是孙子节点
			replace_node(root, y, y->right_child);
			replace_node(root, item, y);

			y->left_child = item->left_child;
			y->right_child = item->right_child;

			item->left_child->parent = y;
			item->right_child->parent = y;
		}else{
			replace_node(root, item, y);
			y->left_child = item->left_child;
			item->left_child->parent = y;
		}
	}else if(item->left_child != NULL || item->right_child != NULL){//该节点有一个孩子
		if(item->left_child != NULL){//只有左孩子
			replace_node(root, item, item->left_child);
		}else{
			replace_node(root, item, item->right_child);
		}
	}else{//该节点没有孩子
		replace_node(root, item, NULL);
	}

	free(item);
	return 1;
}
