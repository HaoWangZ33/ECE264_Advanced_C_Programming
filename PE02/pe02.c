#include <stdio.h>
#include <stdlib.h>
// you do not have to include pe02_aux.h here because you are not 
// calling the function function_to_be_integrated here
#include "answer02.h"
#include <string.h>

// fill in the correct statements to complete the main function
// we expect four arguments:
//
// the first argument is two characters from the sets {"-m", "-t"}
// -m: run mid_point_numerical_integration
// -t: run trapezoidal_numerical_integration
// otherwise: return EXIT_FAILURE
      
// to run any of the two functions, expect the next three arguments
// to be the lower limit of the integration (double), the upper limit
// of the integration (double), and the number of intervals for the
// integration (int)
//
// if the number of intervals is less than 1, set it to 1

// use atof to convert an argument to a double 
// use atoi to convert an argument to an int

// after you have numerically integrated the function, print the 
// return value, and return EXIT_SUCCESS
//

int main(int argc, char * * argv)
{
   double integral = 0.0;
   double lower_limit = 0.0;
   double upper_limit = 0.0;
   int interval = 0;
   if(argc == 5){
      if(strcmp(argv[1],"-m") == 0){
	     lower_limit = atof(argv[2]);
		 upper_limit = atof(argv[3]);
		 interval = atoi(argv[4]);
		 if(interval < 1){
		    interval = 1;
	     }
         integral = mid_point_numerical_integration(lower_limit, upper_limit, interval);
	  }
	  else if(strcmp(argv[1],"-t") == 0){
	     lower_limit = atof(argv[2]);
		 upper_limit = atof(argv[3]);
		 interval = atoi(argv[4]);
		 if(interval < 1){
		    interval = 1;
	     }
		 integral = trapezoidal_numerical_integration(lower_limit, upper_limit, interval);
	  }
	  else{
	     return EXIT_FAILURE;
	  }
   }
   else{
      return EXIT_FAILURE;
   }

   printf("%.10e\n", integral);
   return EXIT_SUCCESS;
}
