#include <stdio.h>

int main(){
	int var1 = 0,var3,var4, var2 = 0;
	int *ptr = (int *)0x2c;
	int temp = 0, vartemp = 0;
	temp = (char *) ptr - (char *)0x21;
	vartemp = (&var1 - &var3 );
	printf("%d\n",temp);
	printf("%p\n",&var1);
	printf("%p\n",&var2);
		printf("%d\n",vartemp);
	return 0;
}
