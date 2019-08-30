#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#define TRUE 1
#define FALSE 0

struct tree_node
{
    int data;

    struct tree_node *left;
    struct tree_node *right;
}tree_node;
typedef struct tree_node TreeNode;
typedef struct tree_node *BinaryTree;

BinaryTree createBinaryTree();

BinaryTree insertBinaryTreeRecursive(BinaryTree tree, int val);
BinaryTree insertBinaryTreeIteration(BinaryTree tree, int val);

void preorderTraversal(BinaryTree tree);
void inorderTraversal(BinaryTree tree);
void postorderTraversal(BinaryTree tree);

void levelTraversal(BinaryTree tree);

unsigned int isEmptyTree(BinaryTree tree);

void destoryBinaryTree(BinaryTree tree);

#endif