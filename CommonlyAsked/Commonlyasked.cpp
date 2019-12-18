#include <stdio.h>
#define SQUARE(a) (a)*(a)

int main() {
	int a=-4;
	int b= 5;
	int c = 0;
	
	printf("%d %d\n",b++,b);
    printf("%d\n", SQUARE(4));
    int x = 3;
    printf("%d\n", SQUARE(++x));
    printf("%d\n", (++x) * (++x));    // first it ll increment both then multiplication is performed
    printf("%x\n",a>>0);
    printf("%x",~c);
}

