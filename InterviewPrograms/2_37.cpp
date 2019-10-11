#include <stdio.h>
#include <string.h>

int main(void)
{

int x = 2, y;
y = x<<1;
 printf("X before :%d\n",y);
    printf("X before :%d\n",x);
    x = (x<<x<<x) | (x<<x<<x) |  x<<!!x | !!x ;
    printf("X After  :%d\n",x); 
}
