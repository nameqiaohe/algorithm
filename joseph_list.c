/*####################################################
# File Name: Joseph_list.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-15 20:10:34
# Last Modified: 2016-06-15 20:10:34
####################################################*/
#include <stdio.h>
#include <stdlib.h>

typedef struct point{
	int index;
	struct point *next;
}Node, *Link;

int max, flag;

//创建约瑟夫环
Link create_joseph_list(){
	int i;
	Link head, tail, new;
	head = NULL;

	printf("enter two numbers(max, flag): \n");
	scanf("%d", &max);
	scanf("%d", &flag);

	for(i = 1; i <= max; i++){
		new = (Link)malloc(sizeof(Node));
		new->index = i;
		if(head == NULL){
			head = new;
			tail = new;
		}else{
			tail->next = new;
			tail = new;
		}
	}
	tail->next = head;
	return head;
}

//按规则数数，数到flag的人退出
void count_falg(Link head){
	if(head == NULL)
		return;

	int count = 1;
	int num = 0;
	Link pre, ptr;
	ptr = head;

	while(num < max){
		do{
			count++;
			pre = ptr;
			ptr = ptr->next;
		}while(count < flag);

		printf("kick out : %d\n", ptr->index);

		pre->next = ptr->next;
		free(ptr);

		ptr = pre->next;
		count = 1;
		num++;
	}
}

int main(int argc, char *argv[]){
	Link head = create_joseph_list();
	
	count_falg(head);

	return 0;
}
