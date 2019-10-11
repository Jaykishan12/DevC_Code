#include <stdio.h>
#include <string.h>
struct mStruct
{
    char name[10];
    int age;
    float height;
};

union mUnion
{
    char name[15];
    int age;
    float height;
};

int main(void)
{
    union  mUnion  uTest;
    struct mStruct sTest;
    strcpy(sTest.name,"sTest");
    sTest.age    = 20;
    sTest.height = 6.1;
    strcpy(uTest.name ,"uTest");
    uTest.height = 6.0;
    uTest.age    = 20;
    printf("\n");
    printf("sizeof(uTest) = %d ,sizeof(sTest) = %d \n",sizeof(uTest),sizeof(sTest));
    printf("uTest.age = %d , uTest.height = %f , uTest.name = %d\n",uTest.age, uTest.height, uTest.name[0]);
    printf("sTest.age = %d , sTest.height = %f , sTest.name = %s\n",sTest.age, sTest.height, sTest.name);
    printf("\n");
}
