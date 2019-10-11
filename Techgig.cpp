#include "stdio.h"

void rec(int n){
	if( n == 0)
		return;
	rec(n - 1);
	printf("%d\n",n);
}

struct marks{
	int p:3;
	int c:3;
	int m:2;
};

int fi(int x){
//	if(x == 4)
		return x;
	return fi(--x);
}

int main(){
	static int qz;
	if(qz++ < 2)
		main();
	char achar[] = "hello hi";
//	printf("%d%d",sizeof(*achar),sizeof(achar));
	
	int a[5] = { 51, 1 , 5 , 20 , 2};
	int x, y, z;
	x = ++a[1];
	y = a[1]++;
	z = a[x++];
	printf("%d %d %d %d %d",a[-1],a[7], x, y, z);
	struct marks s = {2,-6,5};
//	printf("%d %d %d \n", s.p, s.c ,s.m);
/*	int  i =320;
	char *ptr =  &i;
	printf("%d", *ptr);*/
//	printf("%d\n", fi(7));
/*	int arr[5], i = 0;
	for( i = 1; i = 5; i ++){
		scanf("%d", &arr[i]);
		printf("%d\n", arr[i]);
	}*/
/*	rec(10);
	return 0;*/
/*	int x = 1, y = 12, z = 123;
	z *= x *= y;
	printf("%d %d %d",z,x,y);*/
}
