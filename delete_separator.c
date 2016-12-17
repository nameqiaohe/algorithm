/*####################################################
# File Name: delete_separator.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2016-12-17 17:13:07
# Last Modified: 2016-12-17 17:21:20
####################################################*/

int find_separator(char *src, char separator, int index){
	if(src == NULL){
		return -1;
	}

	if(src[index] == '\0'){
		return -1;
	}

	int flag = -1;
	while(src[index] != '\0'){
		if(src[index] == separator){
			flag = index;
			break;
		}
		++index;
	}
	return flag;
}

//这里的 dst 是一块在调用之前已经分配好的内存，或者在栈上，或者在堆上
//这个方法内部完成了内存的分配与释放
char *delete_separator(char *dst, const char *src, char separator){
	int len = strlen(src);
	int index = 0;

	char *temp = (char *)malloc(len);
	strncpy(temp, src, len);

	while((index = find_separator(temp, separator, index) != -1)){
		memset(dst, '\0', strlen(dst));
		//bzero(dst, strlen(dst));
		strncpy(dst, temp, index);
		strncpy(dst + strlen(dst), temp + index + 1, strlen(temp) - index - 1);
		strncpy(temp, dst, strlen(dst));
		temp[--len] = '\0';
	}

	free(temp);

	return dst;
}
