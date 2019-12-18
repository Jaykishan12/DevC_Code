#include<stdio.h>
void my_function() {
   printf("This is a normal function.");
}
void my_callback_function(void (*ptr)()) {
   printf("This is callback function.\n");
   (*ptr)();   //calling the callback function
}
main() {
   void (*ptr)() = &my_function;
   my_callback_function(ptr);
}
