#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "stdlib.h"

void swap(char *c, char *temp);

int main(){
	uint8_t len = 0, i = 0, j = 0;
	char *s = "kishan", *ptr = NULL, temp1;
	char str[] = "Geeks for Geeks1";
	char *strptr = NULL;
	char* token = strtok(str, " ");
	
	len = strlen(str);
	strptr =  (char *)malloc((len) * sizeof(char));
	printf("Enter a string\n");
	printf("%s\n",s);
	len = strlen(s);
	ptr = (char *)malloc((len) * sizeof(char));
	printf("%d\n",len);
//	strcpy(ptr,s);
//	strrev(ptr);
	j = len - 1;
	for(i = 0;i < len; i++, j--){
		ptr[i] = s[j];
	}
	ptr[len] = '\0';
	printf("AFter reversing\n");
	printf("%s\n",ptr);
	printf("Using Single buffer\n");
	j = len - 1;
	for(i = 0; i < (len / 2); i++,j--){
		temp1 = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = temp1;
	}
	printf("AFter reversing\n");
	printf("%s\n",ptr);
	 while (token != NULL) { 
        printf("%s\n", token); 
        token = strtok(NULL, " "); 
        strcpy(strptr, token);
    } 
    printf("Token Values %s", strptr);
}


/*Two things to know about strtok. As was mentioned, it "maintains internal state". Also, it messes up the string you feed it. Essentially, it will write a '\0' where it finds the token you supplied, and returns a pointer to the start of the string. Internally it maintains the location of the last token; and next time you call it, it starts from there.

The important corollary is that you cannot use strtok on a const char* "hello world"; type of string, since you will get an access violation when you modify contents of a const char* string.

The "good" thing about strtok is that it doesn't actually copy strings - so you don't need to manage additional memory allocation etc. But unless you understand the above, you will have trouble using it correctly.

Example - if you have "this,is,a,string", successive calls to strtok will generate pointers as follows (the ^ is the value returned). Note that the '\0' is added where the tokens are found; this means the source string is modified:

t  h  i  s  ,  i  s  ,  a  ,  s  t  r  i  n  g \0         this,is,a,string

t  h  i  s  \0 i  s  ,  a  ,  s  t  r  i  n  g \0         this
^
t  h  i  s  \0 i  s  \0 a  ,  s  t  r  i  n  g \0         is
               ^
t  h  i  s  \0 i  s  \0 a  \0 s  t  r  i  n  g \0         a
                        ^
t  h  i  s  \0 i  s  \0 a  \0 s  t  r  i  n  g \0         string*/

void swap(char *c, char *temp){
	char temp1;
	
	
}
