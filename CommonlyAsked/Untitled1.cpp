#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(){
	int i = 0;
	int8_t string[10] = "kishan";
	int8_t **ptr = (int8_t **)malloc(sizeof(int8_t *) * 2);
	for(i = 0; i < 2; i++){
		ptr[i]= (int8_t *)malloc(sizeof(int8_t) * 16);
		memset(*(ptr + i),0x00,sizeof(int8_t) * 16);
	}
	strcpy((char *)*(ptr + 0),(char *)string);
	printf("%s\n", *(ptr ));
		strcpy((char *)*(ptr + 1),(char *)"hey");
	printf("%s", *(ptr + 1));
}
