#include <stdio.h>

int main(int argc, char *argv[]){
	char Buffer[100] = "kishan";
    char *ptr = Buffer; //the addr you wish to access the contents of
    char ch = *(Buffer + 3);
 //   ptr++;
    printf("%c\n", *(ptr + 3)); //this will give you the first byte, you can add any more bytes you need to the ptr itself, like so: *(ptr + nbyte).
	printf("%c\n", *(Buffer + 3));
	printf("%c\n", ch);
    return 0;
}
