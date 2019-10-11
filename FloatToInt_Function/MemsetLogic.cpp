#include <stdio.h>
#include "stdint.h"
#include "string.h"
#include<stdlib.h>
#define LEN 10

typedef struct demostruct{
	int value;
	char buff[10];
};

struct demostruct demo[] = {
		{10,"kishan"}
};

//memset() function implemention
//function name: myMemSet()
void myMemSet(void* str, char ch, size_t n){
	int i;
	//type cast the str from void* to char*
	char *s = (char*) str;
	//fill "n" elements/blocks with ch
	for(i=0; i<n; i++)
		s[i]=ch;
}

void myMemCpy(void *dest, void *src, size_t n) 
{ 
   // Typecast src and dest addresses to (char *) 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
  
   // Copy contents of src[] to dest[] 
   for (int i=0; i<n; i++) 
       cdest[i] = csrc[i]; 
} 

//int own_memcmp(const void *buf1, const void *buf2, int cnt)
//{
//	if(!cnt)
//	{
//		return 0;	
//	}
//	while(--cnt && (*(char *)buf1 == *(char *)buf2))
//	{
//	
//	buf1 = (char *)buf1 + 1;
//	buf2 = (char *)buf2 + 1;
//	
//	}
//	return ( *((unsigned char *)buf1) – *((unsigned char *)buf2));
//
//}

unsigned int my_memcmp(const void *b,const void *c, int len)
{
    unsigned char *p = (unsigned char *)b;
    unsigned char *q = (unsigned char *)c;

    while (len > 0)
    {
        if (*p != *q)
            return (*p - *q);
        len--;
        p++;
        q++;
    }
    return 0;
}

int main(void) {
	char arr[LEN];
	char Buffer[100];
	int loop;
	
	char *ptr = NULL;
		char *ptr1 = NULL;
	unsigned int diff = 0;

	ptr = (char*)malloc(25);
	ptr1 = (char*)malloc(25);

	printf("Enter value of ptr nad ptr1\n");
	gets(ptr);
	gets(ptr1);
	
	diff = my_memcmp(ptr, ptr1, 10);
	printf("Diff = %d\n",diff);
	
	free(ptr);
	free(ptr1);
	
	printf("Structure Elemnets\n");
	printf("%d %s",demo[0].value,demo[0].buff);
	printf("\n");

	printf("Array elements are (before myMemSet()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");
	

	//filling all blocks with 0
	myMemSet(arr,0,LEN);
	myMemSet(&demo,0,sizeof(demo));
	printf("Array elements are (after myMemSet()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");
	// Mem Copy Function
	strcpy(Buffer,"KISHAN");
	myMemCpy(arr,Buffer,strlen(Buffer));
	printf("%s ",arr);
	
	printf("Structure Elemnets\n");
	printf("%d %s",demo[0].value,demo[0].buff);
	printf("\n");
	//filling first 3 blocks with -1
	//and second 3 blocks with -2
	//and then 3 blocks with -3
	myMemSet(arr,-1,3);
	myMemSet(arr+3,-2,3);
	myMemSet(arr+6,-3,3);
	printf("Array elements are (after myMemSet()): \n");
	for(loop=0; loop<LEN; loop++)
		printf("%d ",arr[loop]);
	printf("\n");

	return 0;
}
