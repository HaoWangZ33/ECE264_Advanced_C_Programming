// do not change this part, if you do, your code may not compile
//
/* test for structure defined by student */
#ifndef NTEST_STRUCT 
#include "answer03.h"
#else 
#include "answer03_key.h"
#endif /* NTEST_STRUCT */
//
// do not change above this line, if you do, your code may not compile
// This is the only file you have to include 

// Given intg_arg, this function performs numerical integration of 
// the function intg_arg.func_to_be_integrated over the range
// intg_arg.lower_lilmit to intg_arg.upper_limit
// 
// The range is divided into intg_arg.n_intervals uniform intervals, where the
// left-most interval has a left boundary of intg_arg.lower_limit and the 
// right-most interval has a right boundary of intg_arg.upper_limit (assuming 
// intg_arg.lower_limit <= intg_arg.upper_limit).  
// If intg_arg.lower_limit >= intg_arg.upper_limit, the right-most interval 
// has a right boundary of intg_arg.lower_limit and the left-most interval has 
// a left boundary of intg_arg.upper_limit.
// 
// The Simpson's rule is used to perform the integration for each interval
// In the Simpson's rule, three points are used to approximate the 
// intg_arg.func_to_be_integrated.  The three points are:
// (left boundary, intg_arg.func_to_be_integrated(left boundary)), 
// (right boundary, intg_arg.func_to_be_integrated(right boundary)),
// (mid-point, intg_arg.function_to_be_integrated(mid-point)).  
// mid-point is the middle of the left and right boundary.
// A quadratic equation that passes through these three points is used
// to approximate the intg_arg.func_to_be_integrated
// The integration of the quadratic equation yields
// (width of interval)/6 * (f(left) + 4*f(mid-point) + f(right))
// Here, f is short for intg_arg.func_to_be_integrated
// The width of the interval is (interval boundary closer to 
// intg_arg.upper_limit - interval boundary closer to intg_arg.lower_limit).  
// Note that width could be negative if intg_arg.upper_limit < 
// intg_arg.lower_limit
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that intg_arg.n_intervals >= 1
// Therefore, this function may assume that intg_arg.n_intervals >= 1
//
double simpson_numerical_integration(integrand intg_arg)
{
   double integral  = 0.0;
   double interval  = 0.0;
   double left      = 0.0;
   double right     = 0.0;
   double mid_point = 0.0;
   int count        = 0;

   interval = (intg_arg.upper_limit - intg_arg.lower_limit) / intg_arg.n_intervals;
   left     = intg_arg.lower_limit;
   right    = left + interval;

   for(count = 0; count < intg_arg.n_intervals; count++){
      mid_point = (left + right) / 2;
	  integral += (interval / 6) * (intg_arg.func_to_be_integrated(left) + 4 * intg_arg.func_to_be_integrated(mid_point) +
	              intg_arg.func_to_be_integrated(right));
	  left      = left + interval;
	  right     = right + interval;
   }

   return integral;
}
