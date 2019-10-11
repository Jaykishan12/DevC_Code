#include<stdio.h>
#include<stdlib.h>  

int main() {
  char *s,*p;

  s = (char *)malloc(10);
  scanf("%255s", s); // Don't read more than 255 chars
  printf("%s", s);

  // No need to malloc `p` here
  scanf("%as", &p); // GNU C library supports this type of allocate and store.
  printf("%s", p);
  free(s);
  free(p); 
  return 0;
}
