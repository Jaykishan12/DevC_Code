#include <stdio.h>

int main(){
	int num = 1234;
	int *ptr = &num;
	int **ptr1 = &ptr;
	
	printf("1: %d\n",num);
	printf("2: %x\n",ptr);
	printf("3: %x\n",*ptr1);
	printf("4: %d\n",**ptr1);
}
