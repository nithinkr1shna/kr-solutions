#include <stdio.h>
#include <limits.h>

int main() {


   printf("The minimum value of signed char = %d\n", SCHAR_MIN);
   printf("The maximum value of signed char = %d\n", SCHAR_MAX);
   printf("The maximum value of unsigned char = %d\n", UCHAR_MAX);

   printf("The minimum value of short int = %d\n", SHRT_MIN);
   printf("The maximum value of short int = %d\n", SHRT_MAX); 

   printf("The minimum value of int = %d\n", INT_MIN);
   printf("The maximum value of int = %d\n", INT_MAX);

   printf("The minimum value of char = %d\n", CHAR_MIN);
   printf("The maximum value of char = %d\n", CHAR_MAX);

   printf("The minimum value of long = %ld\n", LONG_MIN);
   printf("The maximum value of long = %ld\n", LONG_MAX);
  
   return(0);
}
