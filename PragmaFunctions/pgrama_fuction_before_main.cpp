#include <stdio.h>
#include "conio.h"
/*
The output of the above program will be -

In fun
In main
But this pragma directive is compiler dependent. Gcc does not support this. So, it will ignore the startup directive and will produce no error. 
But the output in that case will be -

In main

*/
#pragma startup fun
void fun()
{
 printf("In fun\n");
}
main()
{
 printf("In main\n");
}
