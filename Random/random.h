#ifndef RANDOM_H
#define RANDOM_H
double randd_uniform(void); /* Function that returns a double between 0 and 1. NOT CRYPTOGRAPHICALLY SECURE. Passed Chi-Square test. */  
double randd_std_norm(void); /* Function that returns a normal distributed random number. Uses the Box-Muller transform. USES RANDD_UNIFORM, WHICH IS NOT CRYPTOGRAPHICALLY SECURE. */
#endif