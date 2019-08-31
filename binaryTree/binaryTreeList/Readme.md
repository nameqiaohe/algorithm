# C 语言实现 二叉树

用链表 实现 二叉树
--------------------

## 1. BinaryTree insertBinaryTreeRecursive(BinaryTree tree, int val);
    (1)递归实现 二叉树的插入
    (2)插入规则：按照节点值的大小，左小、右大

## 2. BinaryTree insertBinaryTreeIteration(BinaryTree tree, int val);
    (1)迭代实现 二叉树的插入
    (2)插入规则：按照节点值的大小，左小、右大

## 3. void levelTraversal(BinaryTree tree);
    二叉树的层级遍历，借助队列来实现

## 4. destoryQueue(queue);
    由于这里的queue只分配了queue的空间，queue中的节点都是已经分配好内存的二叉树节点，
    因此只需要释放queue的空间，不需要再迭代释放queue中的节点
