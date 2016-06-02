/*####################################################
# File Name: find_first-single_ch.c
# Author: YanWei
# Email: nameqiaohe@126.com
# Create Time: 2016-06-03 06:34:02
# Last Modified: 2016-06-03 06:34:02
####################################################*/
#include <stdio.h>
#include <assert.h>

#define LENGTH 256
#define MAX_SIZE 1024

char find_first_single_ch(char *str){
	assert(str);

	char hash[LENGTH] = {0};
	char *ptr = str;
	while(*ptr != '\0'){
		hash[*ptr]++;
		ptr++;
	}

	ptr = str;
	while(*ptr != '\0'){
		if(hash[*ptr] == 1)
			return *ptr;
		ptr++;
	}
	return -1;
}

int main(void){
	char str[MAX_SIZE] = {0};
	printf("please enter a string:\n");
	scanf("%s", str);

	char ch = find_first_single_ch(str);
	if(ch == -1){
		printf("\e[33mthere is not a ch just appear once\e[0m\n");
	}else{
		printf("\e[33mthe first single ch is : \e[0m\e[35m%c\e[0m\n", ch);
	}

	return 0;
}
