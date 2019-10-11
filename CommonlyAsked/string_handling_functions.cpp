#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "stdlib.h"

void swap(char *c, char *temp);

int main(){
	uint8_t len = 0, i = 0, j = 0;
	char *s = "kishan", *ptr = NULL, temp1;
	char str[] = "Geeks for Geeks1";
	char *strptr = NULL;
	char* token = strtok(str, " ");
	
	len = strlen(str);
	strptr =  (char *)malloc((len) * sizeof(char));
	printf("Enter a string\n");
	printf("%s\n",s);
	len = strlen(s);
	ptr = (char *)malloc((len) * sizeof(char));
	printf("%d\n",len);
//	strcpy(ptr,s);
//	strrev(ptr);
	j = len - 1;
	for(i = 0;i < len; i++, j--){
		ptr[i] = s[j];
	}
	ptr[len] = '\0';
	printf("AFter reversing\n");
	printf("%s\n",ptr);
	printf("Using Single buffer\n");
	j = len - 1;
	for(i = 0; i < (len / 2); i++,j--){
		temp1 = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = temp1;
	}
	printf("AFter reversing\n");
	printf("%s\n",ptr);
	 while (token != NULL) { 
        printf("%s\n", token); 
        token = strtok(NULL, " "); 
        strcpy(strptr, token);
    } 
    printf("Token Values %s", strptr);
}

void swap(char *c, char *temp){
	char temp1;
	
	
}
