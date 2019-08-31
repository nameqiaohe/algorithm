# C 语言实现 单链表

----------------------

## 1. SinglyList *createSinglyList();
    创建单链表

## 2. int singlyListGet(SinglyList *list, int index);
    根据索引获取链表的节点值

## 3. void singlyListAddAtHead(SinglyList *list, int val);
    头部插入节点

## 4. void singlyListAddAtTail(SinglyList *list, int val);
    尾部插入节点

## 4. void singlyListAddAtIndex(SinglyList *list, int index, int val);
    按照索引 插入节点

## 5. void singlyListDeleteAtIndex(SinglyList *list, int index);
    按照索引 删除节点

## 6. void singlyListReverse(SinglyList **list);
    反转链表

## 7. void singlyListFree(SinglyList *list);
    释放链表

## 8. void displaySinglyList(SinglyList *list);
    打印链表