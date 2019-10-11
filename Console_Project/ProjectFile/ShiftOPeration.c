#include<stdio.h> 
int main() 
{  
   long int i = 3;   
   printf("pow(2, %d) = %d\n", i, 1 << i); 
   i = 4;   
    printf(" %d\n", ((4096 * 13 ) >> 12)); 
   printf("pow(2, %d) = %d\n", i, 1 << i); 
   return 0; 
} 
