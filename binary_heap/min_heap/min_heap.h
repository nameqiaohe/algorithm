/*####################################################
# File Name: min_heap.h
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-17 21:17:04
# Last Modified: 2017-05-17 22:08:50
####################################################*/
#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) ((sizeof(a)) / (sizeof(a[0])))

#define MAX 30

static int m_heap[MAX];//存放数据的数组

static int m_capacity = MAX;//总容量

static int m_size = 0;//实际存储的数据数量

//返回 data在二叉堆中的索引
int get_index(int data);

//最小堆的向下调整法
void min_heap_filter_down(int start, int end);

//删除最小堆中的数据
int min_heap_remove(int data);

//最小堆的向上调整法
void min_heap_filter_up(int start);

//插入数据
int min_heap_insert(int data);

//打印二叉堆
void min_heap_print();

#endif
