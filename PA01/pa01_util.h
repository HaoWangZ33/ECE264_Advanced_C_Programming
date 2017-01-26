#ifndef PA01_UTIL_H
#define PA01_UTIL_H 

// utitlity to plot a function

void function_plot(double (*original_func)(double), 
                   double lower_limit, double upper_limit,
                   double *a_i, double *b_i, int n_terms,
                   char *filename);

// print fourier coefficients 

void print_fourier_coefficients(double *a_i, double *b_i, int n_terms);

#endif
