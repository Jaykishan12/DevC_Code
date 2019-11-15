#include <stdio.h>

int main(){
	int num = 1234;
	int *ptr = &num;
	int **ptr1 = &ptr;
	
	printf("1: %d",num);
	printf("2: %x",ptr);
	printf("3: %x",*ptr1);
	printf("4: %d",**ptr1);
}
