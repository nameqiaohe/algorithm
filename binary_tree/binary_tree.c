#include "binary_tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

BinaryTree createBinaryTree(){
    return NULL;
}

unsigned int isEmptyTree(BinaryTree tree){
    if(tree == NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

BinaryTree insertBinaryTreeRecursive(BinaryTree tree, int val){
    if(isEmptyTree(tree) == TRUE){
        tree = (TreeNode *)malloc(sizeof(TreeNode));
        if(tree == NULL){
            perror("malloc space for node failed!");
            return NULL;
        }
        tree->data = val;
        tree->left = NULL;
        tree->right = NULL;
    }else if(tree->data > val){
        tree->left = insertBinaryTreeRecursive(tree->left, val);
    }else if(tree->data < val){
        tree->right = insertBinaryTreeRecursive(tree->right, val);
    }

    return tree;
}

BinaryTree insertBinaryTreeIteration(BinaryTree tree, int val){
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if(node == NULL){
        perror("malloc space for node failed!");
        return NULL;
    }

    node->data = val;
    node->left = NULL;
    node->right = NULL;

    if(isEmptyTree(tree) == TRUE){
        tree = node;
        return tree;
    }

    TreeNode *head = tree;
    TreeNode *father = NULL;
    while(head){
        father = head;

        if(head->data > val){
            head = head->left;
        }else if(head->data < val){
            head = head->right;
        }else{
            printf("The value %d already exist!\n", val);
            return tree;
        }
    }
    if(father->data > val){
        father->left = node;
    }else{
        father->right = node;
    }

    return tree;
}


void preorderTraversal(BinaryTree tree){
    if(isEmptyTree(tree) == TRUE){
        // printf("The tree is empty!\n");
        return ;
    }

    printf("%d, ", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

void inorderTraversal(BinaryTree tree){
    if(isEmptyTree(tree) == TRUE){
        printf("The tree is empty!\n");
        return ;
    }

    preorderTraversal(tree->left);
    printf("%d, ", tree->data);
    preorderTraversal(tree->right);
}

void postorderTraversal(BinaryTree tree){
    if(isEmptyTree(tree) == TRUE){
        printf("The tree is empty!\n");
        return ;
    }

    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
    printf("%d, ", tree->data);
}

void levelTraversal(BinaryTree tree){
    if(isEmptyTree(tree) == TRUE){
        printf("The tree is empty!\n");
        return ;
    }

    Queue queue = initQueue();
    queue = pushQueue(queue, tree);
    while(isEmptyQueue(queue) != 0){
        TreeNode *treeNode = popQueue(queue);
        printf("%d, ", treeNode->data);

        if(treeNode->left != NULL){
            queue = pushQueue(queue, treeNode->left);
        }
        if(treeNode->right != NULL){
            queue = pushQueue(queue, treeNode->right);
        }
    }
    printf("\n");

    destoryQueue(queue);
}

void destoryBinaryTree(BinaryTree tree){
    if(isEmptyTree(tree) == TRUE){
        // printf("The tree is empty!\n");
        return ;
    }

    destoryBinaryTree(tree->left);
    destoryBinaryTree(tree->right);
    free(tree);
}