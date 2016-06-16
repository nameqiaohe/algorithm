/*####################################################
# File Name: palindrome.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-16 19:47:12
# Last Modified: 2016-06-16 19:47:12
####################################################*/
#include <stdio.h>

//判断 是否为 回文字符串
int is_palindrome(char *str){
	if(str == NULL)
		return -1;

	char *left = str;
	char *right = str;
	while(*right != '\0')
		right++;

	right--;
	while(left < right){
		if(*left != *right){
			return -1;
		}else{
			left++;
			right--;
		}
	}

	return 1;
}

int main(int argc, char *argv[]){
	char str[100] = {0};

	printf("enter a string:\n");
	scanf("%s", str);

	int result = is_palindrome(str);
	printf("palindrome : %s\n", result == 1 ? "yes" : "no");

	return 0;
}
