#include <stdio.h>

int main(){
	 unsigned char x,y;
	 x = 0x6E;
	  switch (x&0xc0) /*  col.and.0xC0 */
 		 {   /*条件分支执行  */
 			  case 0: {printf("case 0");break;}/*左区 */
 			  case 0x40: {printf("case 1");break;}/*中区 */
 			  case 0x80: {printf("case 2");break;}/*右区 */
 		}
}























