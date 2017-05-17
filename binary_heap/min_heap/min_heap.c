/*####################################################
# File Name: min_heap.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-17 21:28:21
# Last Modified: 2017-05-17 22:10:44
####################################################*/
#include "min_heap.h"

/*
 * 返回data在二叉堆中的索引
 * 返回值：
 *		存在 -- 返回data在数组中的索引
 *		不存在 -- -1
 * */
int get_index(int data){
	int i = 0;

	for(i = 0; i < m_size; ++i){
		if(data == m_heap[i]){
			return i;
		}
	}

	return -1;
}

/*
 * 最小堆的向下调整算法
 *		注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 * 参数说明：
 *		start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *		end   -- 截至范围(一般为数组中最后一个元素的索引)
 * */
void min_heap_filter_down(int start, int end){
	int cur = start;// 当前(current)节点的位置
	int l_index = 2 * cur + 1;//左(left)孩子的位置
	int tmp = m_heap[cur];//当前(current)节点的值

	while(l_index <= end){
		// l_index 是左孩子，l_index + 1是右孩子
		// 左右两孩子中选择较大者，即m_heap[l_index + 1]
		if(l_index < end && m_heap[l_index] < m_heap[l_index + 1]){
			l_index++;
		}

		if(tmp <= m_heap[l_index]){
			break;//调整结束
		}else{
			m_heap[cur] = m_heap[l_index];
			cur = l_index;
			l_index = 2 * l_index + 1;
		}
	}

	m_heap[cur] = tmp;
}

/*
 * 删除最小堆中的data
 * 返回值：
 *		0，成功
 *		-1，失败
 * */
int min_heap_remove(int data){
	int index;

	// 如果二叉堆已空，则返回-1
	if(m_size == 0){
		return -1;
	}

	index = get_index(data);// 获取data在数组中的索引
	if(index == -1){
		return -1;
	}

	m_heap[index] = m_heap[--m_size];// 用最后元素填补
	min_heap_filter_down(index, m_size - 1);// 从index位置开始自上向下调整为最大堆

	return 0;
}

/*
 * 最小堆的向上调整算法(从start开始向上直到0，调整堆)
 *		注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 * 参数说明：
 *		start -- 被上调节点的起始位置(一般为数组中最后一个元素的索引)
 * */
void min_heap_filter_up(int start){
	int cur_index = start;// 当前节点(current)的位置
	int p_index = (cur_index - 1)/2;	// 父(parent)结点的位置
	int tmp = m_heap[cur_index];//当前节点(current)的值

	while(cur_index > 0){
		if(m_heap[p_index] <= tmp){
			break;
		}else{
			m_heap[cur_index] = m_heap[p_index];
			cur_index = p_index;
			p_index = (p_index - 1)/2;
		}
	}

	m_heap[cur_index] = tmp;
}

/*
 * 将data插入到二叉堆中
 * 返回值：
 *		0，表示成功
 *		-1，表示失败
 * */
int min_heap_insert(int data){
	// 如果二叉堆已满，则返回
	if(m_size == m_capacity){
		return -1;
	}

	m_heap[m_size] = data;
	min_heap_filter_up(m_size);
	m_size++;

	return 0;
}

/*
 * 打印二叉堆
 * */
void min_heap_print(){
	int i = 0;
	for(i = 0; i < m_size; ++i){
		printf("%d ", m_heap[i]);
	}
}
