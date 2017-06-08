/*####################################################
# File Name: binary_tree.h
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-25 21:13:25
# Last Modified: 2017-05-25 21:58:17
####################################################*/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef int elem_type;

typedef struct node{
	elem_type data;
	struct node *left_child, *right_child, *parent;
}node;

/* 插入节点：成功返回 1，失败返回 0 */
int tree_insert(node **root, elem_type key);//树中不能有相等的值

/* 查找，若存在，则返回指向该节点的指针，否则返回NULL */
node *tree_find(node *root, elem_type key);

/* 删除值为item的节点，删除成功返回 1，否则返回 0(不存在该节点) */
int tree_delete(node **root, elem_type key);

/* 替换：用节点 y 替换 节点 x */
void replace_node(node **root, node *x, node *y);

/* 中序遍历：按顺序序输出 */
void mid_traversal(node *root);

#endif
