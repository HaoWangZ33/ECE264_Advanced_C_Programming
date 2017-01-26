#include "answer02.h"
#include "pe02_aux.h"

// the function performs numerical integration of the function
// double function_to_be_integrated(double) over the 
// range lower_limit to upper_limit using the mid-point rule
//
// The range is divided into n_intervals uniform intervals, where the
// left-most interval has a left boundary of lower_limit and the 
// right-most interval has a right boundary of upper_limit (assuming 
// lower_limit <= upper_limit).  
// If lower_limit >= upper_limit, the right-most interval has a right 
// boundary of lower_limit and the left-most interval has a left boundary
// of upper_limit.
// 
// The mid-point rule is used to perform the integration for each interval.
// In the mid-point rule, the integration is approximated by using the
// area of a rectangle, where the height of the rectange is obtained by
// function_to_be_integrated(mid-point of the interval).  The width of
// the rectangle is (interval boundary closer to upper_limit - interval
// boundary closer to lower_limit).  Note that width could be negative
// if upper_limit < lower_limit
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that n_intervals >= 1
// Therefore, this function may assume that n_intervals >= 1
//
double mid_point_numerical_integration(double lower_limit, double upper_limit, int n_intervals)
{
   double integral = 0.0;
   double interval = 0.0;
   int count = 0;
   double left = 0.0;
   double right = 0.0;
   double mid_point = 0.0;
   double value = 0.0;

   interval = (upper_limit - lower_limit) / n_intervals;
   left = lower_limit;
   right = left + interval;
   for(count = 0; count < n_intervals; count++){
      mid_point = (left + right) / 2;
      value = function_to_be_integrated(mid_point);
	  integral += value * interval;
	  left = left + interval;
	  right = right + interval;
   }

   return integral;
}

// the function performs numerical integration of the function
// double function_to_be_integrated(double) over the 
// range lower_limit to upper_limit using the trapezoidal rule
//
// The range is divided into n_intervals uniform intervals, where the
// left-most interval has a left boundary of lower_limit and the 
// right-most interval has a right boundary of upper_limit (assuming 
// lower_limit <= upper_limit).  
// If lower_limit >= upper_limit, the right-most interval has a right 
// boundary of lower_limit and the left-most interval has a left boundary
// of upper_limit.
// 
// The trapezoidal rule is used to perform the integration for each interval.
// In the trapezoidal rule, the integration is approximated by the area of 
// a trapezoid, where the heights of the parallel boundaries of the trapezoid
// are obtained by 
// function_to_be_integrated(left boundary of the interval) and 
// function_to_be_integrated(right boundary of the interval).  
// The width of the trapezoid is (interval boundary closer to upper_limit - 
// interval boundary closer to lower_limit).  Note that width could be negative
// if upper_limit < lower_limit
// the area of a trapezoid is the average of the two heights multiplied by
// the width
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that n_intervals >= 1
// Therefore, this function may assume that n_intervals >= 1
//
double trapezoidal_numerical_integration(double lower_limit, double upper_limit, int n_intervals)
{
   double integral = 0.0;
   double interval = 0.0;
   int count = 0;
   double left = 0.0;
   double right = 0.0;
   double value_a = 0.0;
   double value_b = 0.0;

   interval = (upper_limit - lower_limit) / n_intervals;
   left = lower_limit;
   right = left + interval;
   for(count = 0; count < n_intervals; count++){
      value_a = function_to_be_integrated(left);
	  value_b = function_to_be_integrated(right);
	  integral += interval * (value_a + value_b) / 2;
	  left = left + interval;
	  right = right + interval;
   }

   return integral;
}
