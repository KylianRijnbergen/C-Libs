#include "complex.h"
#ifndef MY_POLYNOMIALS_H
#define MY_POLYNOMIALS_H
/* First order */
typedef struct first_order_solutions { 
	int num_sols;
	double sol0; 
} first_order_solutions;

/* Second order */
typedef struct second_order_solutions { 
	int num_sols;
	double sol0, sol1;
} second_order_solutions;

/* Third order */
typedef struct third_order_solutions { 
	int num_sols;
	complex sol0; /* If a, b, c, and d are real, the equation has at least one real root */
	complex sol1, sol2; /* Two of the roots may be complex */
} third_order_solutions;

first_order_solutions solve_first_order(double a, double b);
second_order_solutions solve_second_order(double a, double b, double c);
third_order_solutions solve_third_order(double a, double b, double c, double d);
#endif