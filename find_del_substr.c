/*####################################################
# File Name: find_del_substr.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-16 19:19:40
# Last Modified: 2016-06-16 19:19:40
####################################################*/
#include <stdio.h>

//计算字符串长度
int cal_len(char *str){
	if(str == NULL)
		return 0;

	char *ptr = str;
	int count = 0;
	while(*ptr != '\0'){
		count++;
		ptr++;
	}
	return count;
}

//查找子串
char *find_substr(char *str, const char *substr){
	if(str == NULL || substr == NULL)//若有一个字符串为空，直接返回
		return NULL;

	if(cal_len(str) < cal_len(substr)){//若待查询字符串的长度 小于 子串，直接返回
		return NULL;
	}

	char *ptr = str;
	const char *subptr = substr;
	char *prev = str;//标识找到的子串起始位置

	while(*ptr != '\0' && *subptr != '\0'){
		if(*ptr != *subptr){
			ptr++;
			prev = ptr;//更新prev的位置
			subptr = substr;//比较过程中，若出现不相等，则下次比较 要从子串的起始位置比较
		}else if(*ptr == *subptr){
			if(cal_len(ptr) < cal_len(subptr)){//若相等之后，待查询的字符串剩余部分 的长度 小于 子串的剩余部分，则返回
				return NULL;
			}
			ptr++;//ptr、subptr都向后移，用于下次比较
			subptr++;
		}
	}

	if(*subptr == '\0'){//循环结束，若subptr指到了 子串末尾，即表示 待查询字符串中 包含 子串
		return prev;
	}else if(*ptr == '\0'){//循环结束，若ptr指到了 待查询字符串的末尾，但是subptr 还没有指到 子串的尾部，表示没找到子串
		return NULL;
	}
}

//删除子串
void del(char *str, char *flag, int substrlen){
	char *ptr = str;

	while(ptr != flag)
		ptr++;
	
	while(*(flag+substrlen) != '\0'){
		*ptr = *(flag + substrlen);
		ptr++;
		flag++;
	}
	*ptr = '\0';
}

int del_substr(char *str, const char *substr){
	char *result = find_substr(str, substr);
	if(result == NULL){
		return 0;//返回 0：表示没找到子串
	}else{
		del(str, result, cal_len(substr));//删除 待查询字符串中的 子串
		return 1;//返回 1：表示找到子串
	}
}

int main(int argc, char *argv[]){
	char str[100] = {0};
	char substr[100] = {0};

	printf("enter two strings\n");
	scanf("%s", str);
	scanf("%s", substr);

	int result = del_substr(str, substr);
	printf("found : %s\n", result == 1 ? "yes" : "no");
	printf("final str is : %s\n", str);

	return 0;
}
