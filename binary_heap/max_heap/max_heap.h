/*####################################################
# File Name: max_heap.h
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-17 21:17:04
# Last Modified: 2017-05-17 21:28:15
####################################################*/
#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) ((sizeof(a)) / (sizeof(a[0])))

#define MAX 30

static int m_heap[MAX];//存放数据的数组

static int m_capacity = MAX;//总容量

static int m_size = 0;//实际存储的数据数量

//返回 data在二叉堆中的索引
int get_index(int data);

//最大堆的向下调整法
void max_heap_filter_down(int start, int end);

//删除最大堆中的数据
int max_heap_remove(int data);

//最大堆的向上调整法
void max_heap_filter_up(int start);

//插入数据
int max_heap_insert(int data);

//打印二叉堆
void max_heap_print();

#endif
