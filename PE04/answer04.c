#include <stdlib.h>
#include <errno.h>
#include "utility.h"
#include "answer04.h"

// do not modify before this line

// recursive implementation of the conversion of
// the magnitude of a given number to a string
// the sign is taken care of by the long_int_to_string function
// 
void rec_magnitude_long_int_to_string(long int number, int base,
                                      char *intstring, int *stringlen)
{
   // increment the counter for counting the number of recursive calls
   // do not remove this line

   Increment_counter(&number);
   if (number < 0) {
      number = number * (-1);
   }
   // put your code here
   if (number / base) {
      rec_magnitude_long_int_to_string(number / base, base, intstring, stringlen);
   }
   if (number % base < 10) {
	     intstring[*stringlen] = (char) (number % base + '0');
	     *stringlen = *stringlen + 1;
   }
   else if (number % base >= 10) {
	  intstring[*stringlen] = (char) (number % base + 'W');
      *stringlen = *stringlen + 1;
   }
   // decrement the counter after all recursive calls and before
   // you exit from this function
      Decrement_counter();
	  return;
   }

char *long_int_to_string(long int number, int base)
{
   // the real function for long_int_to_string

   char intstring[65];  // 65 because the largest length needed is 
                        // for base 2, 1 byte for the negative sign,
                        // 63 bytes for the magnitude, and 1 byte for null char
   int stringlen = 0;

   if ((base < 2) || (base > 36)) {
      errno = EINVAL;
      return NULL;
   }
   if (number < 0) {
      // place the sign at location 0 of intstring
      intstring[0] = '-';
      // place the number at location 1 of intstring
      stringlen = 1;
   }
   rec_magnitude_long_int_to_string(number, base, intstring, &stringlen);

   // allocate enough space for null character
   char *ret_string = (char *)malloc(sizeof(char) * (stringlen + 1));

   // copy from intstring to ret_string and append '\0'
   int i;
   for (i = 0; i < stringlen; i++) {
      ret_string[i] = intstring[i];
   }
   ret_string[i] = '\0';
   return ret_string;
}
