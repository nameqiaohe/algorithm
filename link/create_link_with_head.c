/*####################################################
# File Name: create_link_with_head.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-19 22:52:32
# Last Modified: 2016-06-19 22:52:32
####################################################*/

typedef struct node{
	int data;
	struct node *next;
}link;

link *create_linki_with_head(int n){
	link *head, *ptr, *new;
	int i;
	if(n < 1){
		return NULL;
	}

	ptr = head = (link *)malloc(sizeof(link));

	for(i = 1; i <= n; i++){
		new = (link *)malloc(sizeof(link));
		scanf("%d", &new->data);
		ptr->next = new;
		ptr = new;
	}
	ptr = next = new;

	return head;
}
