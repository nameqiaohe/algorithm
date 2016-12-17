/*####################################################
# File Name: strcpy.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2016-12-17 17:10:07
# Last Modified: 2016-12-17 17:11:52
####################################################*/

char *strcpy(char *strDest, const char *strSrc){
	aeesrt((strDest != NULL) && (strSrc != NULL));

	char *address = strDest;
	while((*strDest++ = *strSrc) != '\0'){
		;
	}

	return strDest;
}
