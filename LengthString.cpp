#include <stdio.h>
#include <string.h>
 
int main()
{
  char a[500] = { "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiI1Y2RiYmJkZTI0ODMyYmZmNmQzNmY2ZDAiLCJ1c2VydHlwZSI6ImRlZmF1bHQiLCJpYXQiOjE1NTgwOTEyODE4NjksImV4cCI6MTU2MzI3NTI4MTg2OSwiZGV2aWNlSWQiOiI1Y2QxODk4NjI0ODMyYmZmNmQyY2M2NzAiLCJidXNpbmVzc0lkIjoiNWNkMjY3NDc5NjFhODgzYzJhODNhODg2Iiwib3V0bGV0SWQiOiI1Y2Q2YWI5NDdhMWJkYzRmZmEwMzhjN2IifQ.tV9tFRToBOAmLi_i04ARYAm5ciQA7pVfuJnIroIX4oc.jmo-Qo-khiclA4xGHjrm2qs1prEzAJeBRoLeVmjD86g"};
  int length;
 
  length = strlen(a);
 
  printf("Length of the string = %d\n", length);
 
  return 0;
}
