/*####################################################
# File Name: chose_sort_link.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-19 22:33:23
# Last Modified: 2016-06-19 22:33:23
# Descrition: 链表的排序：选择排序、冒泡排序
####################################################*/
#include <stdio.h>

Node *select_sort(Node *head){
	Node *p, *q, *small;
	int temp;

	for(p = head; p->next !=  NULL; p = p->next){
		small = p;
		for(q = p->next; q; q = q->next){
			if(q->data < small->data)
				small = q;
		}

		if(small != p){
			temp = p->data;
			p->data = small->data;
			small->data = temp;
		}
	}
	return head;
}

Node *bubble_sort(Node *head){
	Node *p, *tail, *pnext;
	int temp;

	if(head->next == NULL)
		return head;

	for(tail = head; tail->next == NULL; tail = tail->next){
		;

	while(tail != head->next){
		for(p = head; p->next != tail; p = p->next){
			pnext = p->next;
			if(p->data > pnext->data){
				temp = p->data;
				p->data = pnext->data;
				pnext->data = temp;
			}
		}
		tail = p;
	}
	return head;
}
