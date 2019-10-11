#include <stdio.h>

int main(int argc, char *argv[]){
	char Buffer[100];
    char *ptr = (char *)0x01; //the addr you wish to access the contents of
    sprintf(Buffer,"%c\n", *ptr); //this will give you the first byte, you can add any more bytes you need to the ptr itself, like so: *(ptr + nbyte).

    return 0;
}
