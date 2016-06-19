/*####################################################
# File Name: find_node_link.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-19 22:46:03
# Last Modified: 2016-06-19 22:46:03
####################################################*/
/* 查找链表的 中间节点：
 * 	两个指针：*fast, *slow，都指向head
 * 	fast的移动速度 是 slow的2倍
 * 	当fast 指向 tail时，slow正好中间 */

int get_mid_node(list *head){
	if(head == NULL)
		return -1;

	list *fast, *slow;
	fast = slow = head;

	while(fast->next != NULL){
		if(fast->next->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}else{
			fast = fast->next;
		}
	}
	return slow->data;
}
