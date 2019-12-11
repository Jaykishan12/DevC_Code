#include <stdio.h>
// We can also print ascii table with this
int main(){
	unsigned char ch = 0;                    // if ch is signed char then only -127 to 127 is valid range after that it again enters infinte loop
	for(ch = 0;ch < 255;ch++){     // when ch <= 255 then it enters infintes loop as value after ch = 255 is aain 0
		printf("ASCII[%d] = %c \n",ch,ch);        
	}
}
