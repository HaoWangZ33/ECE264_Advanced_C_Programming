#include <stdio.h>
#include <stdlib.h>
#include "pa01_aux.h"
#include "pa01_util.h"
// do not change this part, if you do, your code may not compile
//
/* test for structure defined by student */
#ifndef NTEST_STRUCT 
#include "answer01.h"
#else
#include "answer01_key.h"
#endif /* NTEST_STRUCT */
//
// do not change above this line, if you do, your code may not compile

int main(int argc, char * * argv)
{
   if (argc != 6){
      return EXIT_FAILURE;
   }
   else if ((argv[1][0] != '1' && argv[1][0] != '2' && argv[1][0] != '3') || argv[1][1] != '\0'){
      return EXIT_FAILURE;
   }
   else{
      fourier fourier_arg;
	  if (argv[1][0] == '1'){
	     fourier_arg.intg.func_to_be_integrated = unknown_function_1;
      }
	  else if (argv[1][0] == '2'){
	     fourier_arg.intg.func_to_be_integrated = unknown_function_2;
	  }
	  else if (argv[1][0] == '3'){
	     fourier_arg.intg.func_to_be_integrated = unknown_function_3;
	  }
	  fourier_arg.intg.lower_limit = atof(argv[2]);
	  fourier_arg.intg.upper_limit = atof(argv[3]);
	  if (fourier_arg.intg.lower_limit == fourier_arg.intg.upper_limit){
	     return EXIT_FAILURE;
	  }
	  fourier_arg.intg.n_intervals = atoi(argv[4]);
	  if (fourier_arg.intg.n_intervals <= 1){
	     fourier_arg.intg.n_intervals = 1;
	  }
	  fourier_arg.n_terms = atoi(argv[5]);
	  if (fourier_arg.n_terms <= 1){
	     fourier_arg.n_terms = 1;
	  }	 
      fourier_arg.a_i = (double *)malloc(sizeof(double)*fourier_arg.n_terms);
      if (fourier_arg.a_i == NULL) {
	     free(fourier_arg.a_i);
         return EXIT_FAILURE;
      }
      fourier_arg.b_i = (double *)malloc(sizeof(double)*fourier_arg.n_terms);
      if (fourier_arg.b_i == NULL) {
         free(fourier_arg.b_i);
         return EXIT_FAILURE;
      }

      fourier_coefficients(fourier_arg);

      print_fourier_coefficients(fourier_arg.a_i, fourier_arg.b_i, fourier_arg.n_terms);

      free(fourier_arg.a_i);
      free(fourier_arg.b_i);

      return EXIT_SUCCESS;
   }
} 
