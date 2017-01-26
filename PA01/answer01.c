#include <math.h>
// do not change this part, if you do, your code may not compile
//
/* test for structure defined by student */
#ifndef NTEST_STRUCT 
#include "answer01.h"
#else 
#include "answer01_key.h"
#endif /* NTEST_STRUCT */

#ifndef NTEST_SIMPSON

double simpson_numerical_integration(integrand intg_arg)
{
   double integral = 0.0;
   double interval = 0.0;
   double left     = 0.0;
   double right    = 0.0;
   double mid_point = 0.0;
   int count       = 0;

   interval = (intg_arg.upper_limit - intg_arg.lower_limit) / intg_arg.n_intervals;
   left     = intg_arg.lower_limit;
   right    = left + interval;

   for (count = 0; count < intg_arg.n_intervals; count++){
      mid_point = (left + right) / 2;
	  integral += (interval / 6) * (intg_arg.func_to_be_integrated(left) + 4 * intg_arg.func_to_be_integrated(mid_point) + 
	              intg_arg.func_to_be_integrated(right));
	  left = left + interval;
	  right = right + interval;
   }
   return integral;
}
// do not change this
#endif /* NTEST_SIMPSON */

#ifndef NTEST_FSIMPSON
double simpson_numerical_integration_for_fourier(integrand intg_arg, int n, double (*cos_sin)(double))
{
   double integral = 0.0;
   double interval = 0.0;
   double left     = 0.0;
   double right    = 0.0;
   double mid_point = 0.0;
   int count       = 0;
   double L        = (intg_arg.upper_limit - intg_arg.lower_limit) / 2;

   interval = (intg_arg.upper_limit - intg_arg.lower_limit) / intg_arg.n_intervals;
   left     = intg_arg.lower_limit;
   right    = left + interval;

   for (count = 0; count < intg_arg.n_intervals; count++){
      mid_point = (left + right) / 2;
	  integral += (interval / 6) * (intg_arg.func_to_be_integrated(left) * cos_sin((n * M_PI * left) / L)
	                          + 4 * intg_arg.func_to_be_integrated(mid_point) * cos_sin((n * M_PI * mid_point) / L)
	                              + intg_arg.func_to_be_integrated(right) * cos_sin((n * M_PI * right) / L));
	  left = left + interval;
	  right = right + interval;
   }
   
   return integral;
}
#endif /* NTEST_FSIMPSON */

#ifndef NTEST_FOURIER
void fourier_coefficients(fourier fourier_arg) 
{
   int i;
   double L = (fourier_arg.intg.upper_limit - fourier_arg.intg.lower_limit) / 2;
   for (i = 0; i < fourier_arg.n_terms; i++) {
      if (i == 0){
	     fourier_arg.a_i[i] = simpson_numerical_integration(fourier_arg.intg) / L;
		 fourier_arg.b_i[i] = 0;
	  }
	  if (i >= 1){
         fourier_arg.a_i[i] = simpson_numerical_integration_for_fourier(fourier_arg.intg, i, cos) / L;
         fourier_arg.b_i[i] = simpson_numerical_integration_for_fourier(fourier_arg.intg, i, sin) / L;
      }
   }
}
#endif /* NTEST_FOURIER */

// IF YOU HAVE TO define more functions, do so after this line
