#include <stdio.h>

int main(int argc, char *argv[]){
	char Buffer[100]= "kishan";
    char *ptr = Buffer; //the addr you wish to access the contents of
 //   ptr++;
    printf("%c\n", ptr); //this will give you the first byte, you can add any more bytes you need to the ptr itself, like so: *(ptr + nbyte).

    return 0;
}
