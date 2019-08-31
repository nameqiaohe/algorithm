#include "binary_tree.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    BinaryTree tree = createBinaryTree();

    int arr[10] = {30, 20, 14, 18, 24, 26, 31, 40, 33, 37};

    int i = 0;
    for (i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        // tree = insertBinaryTreeRecursive(tree, arr[i]);
        tree = insertBinaryTreeIteration(tree, arr[i]);
    }

    printf("----------preorderTraversal\n");
    preorderTraversal(tree);
    printf("\n");

    // inorderTraversal(tree);

    // postorderTraversal(tree);

    levelTraversal(tree);

    destoryBinaryTree(tree);    

    return 0;
}
