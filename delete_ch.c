/*####################################################
# File Name: delete_ch.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-15 19:32:47
# Last Modified: 2017-05-15 20:50:59
####################################################*/
/*
 * str1 : They are my friends
 * str2 : aeiou
 * 删除之后 str1 变成：Thy r my frnds
 * */

#include <stdio.h>
#include <string.h>

#define LEN 256
#define FLAG 257

void delete_ch(char *src, char *target){
	if(src == NULL || target == NULL){
		return;
	}

	int hash_table[LEN];
	int i = 0;
	for(i = 0; i < LEN; i++){
		hash_table[i] = -1;
	}

	int target_len = strlen(target);
	int pos;
	for(i = 0; i < target_len; i++){
		pos = (int)target[i];
		hash_table[pos] = FLAG;
	}

	char *fast = src, *slow = src;
	while(*fast != '\0'){
		if(hash_table[(int)*fast] == -1){
			*slow = *fast;
			slow++;
		}
		fast++;
	}
	*slow = 0;
}

int main(void){
	/*下边这样 会出错
	char *src = "They are my friends!";
	char *target = "aeiou";
	*/
	char src[] = "They are my friends!";
	char target[] = "aeiou";

	delete_ch(src, target);
	printf("after delete, src : %s\n", src);

	return 0;
}

/*
 * 思路：
 * 1、遍历字符串
 *		不可避免的要 遍历 str1，若遍历一个字符串，都需要去第二个字符串中查找其存在不存在，那么复杂度为 O(nm)，由于字符个数有限，所以 m 是个常量。
 *		而 查找速度最快的时 hash表，对于 8 位字符，size = 2^8 足矣 ???
 * 2、删除字符
 *		删除字符，后面的字符要向前移，如果每删除一个字符就移动一次，O(n^2) 这复杂度太高
 *		快慢指针可以解决这个问题，快慢指针还可以求解 循环链表
 *
 * 步骤：
 *		初始化：快慢指针 指向 str1 的第一个字符
 *		循环：如果快指针 指的是不需要的字符，将值赋给慢指针，快慢指针同时自增
 *				如果快指针 指向的时待删除字符，那么直接自增
 *		终止：快指针 指向 '\0'
 * */
