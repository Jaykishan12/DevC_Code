#include <stdio.h>

int main(){
	char *ptr = (char *)0x2c;
	int temp = 0;
	temp = (char *) ptr - (char *)0x21;
	printf("%d\n",temp);
	return 0;
}
