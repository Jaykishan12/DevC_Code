#include "stdio.h"
#include "conio.h"

#pragma pack(1)
typedef struct A
{
char c;
int i;
}B;

//#pragma pack(1)
typedef struct A_packed
{
char c;
int i;
}__attribute__((packed)) packed_data;

int main(){
	int B_size = 0;
	B_size = sizeof(B);
	printf("%d",B_size);
	B_size = sizeof(packed_data);
	printf("%d",B_size);
}

/*
http://a4academics.com/interview-questions/57-c-plus-plus/720-c-interview-questions-experienced
*/
