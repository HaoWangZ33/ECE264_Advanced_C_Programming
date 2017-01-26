#include "answer01.h"

/* Return the largest partial sum of the array */
/* int array[] = { 1, 4, -1, 6, -5, 4} */
/* the (i,j)-th partial sum is the sum from array[i] through array[j], i<=j */
/* the (0,0)-(0,5)-th partial sums are 1, 5, 4, 10, 5, 9 */
/* the (1,1)-(1,5)-th partial sums are 4, 3, 9, 4, 8 */
/* the (2,2)-(2,5)-th partial sums are -1, 5, 0, 4 */
/* the (3,3)-(3,5)-th partial sums are 6, 1, 5 */
/* the (4,4)-(4,5)-th partial sums are -5, -1 */
/* the (5,5)-th partial sum is 4 */
/* the largest partial sum of the array is therefore 10 */
/* if the len is 0, the largest partial sum is 0 */
/* you may assume that array is NULL when len is 0 */
/* but is non-NULL and correct when len is > 0 */
/* you may also assume that none of the partial sums will cause an overflow */

int largest_partial_sum(int * array1, int len1)
{
   if(len1 == 0){
      return 0;
   }
   if(len1 > 0){
      int count1 = 0;  //counter for each row
	  int Lps = 0;
      for(count1 = 0; count1 < len1; count1++){
         int count2;   //counter for each element
		 int P_sum = 0;   //partial sum
	     for(count2 = count1; count2 < len1; count2++){
	        P_sum += array1[count2];
			if(P_sum >= Lps){
			   Lps = P_sum;
			}
		 }	
   }
   return Lps;
}

/* Return the largest difference of the array */
/* int array[] = { 1, 4, -1, 6, -5, 4} */
/* the largest difference is 6 - (-5) = 11 */
/* if the len is 0, the largest difference is 0 */
/* if the len is 1, the largest difference is also 0 */
/* you may assume that array is NULL when len is 0 */
/* but is non-NULL and correct when len is > 0 */
/* you may assume that the largest difference will not cause an overflow */

int largest_difference(int * array2, int len2)
{
   if(len2 == 0){
      return 0;
   }
   else if(len2 == 1){
      return 0;
   }
   else{
      int count;
	  int max = array2[0];
	  int min = array2[0];
      for(count = len2; count < len2; count++){
	     if(array2[count] >= max){
		    max = array2[count];
		 }
		 else if(array2[count] <= min){
		    min = array2[count];
		 }
	  }
   return max - min;
   }
}
