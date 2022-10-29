#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H
/* Complex struct */
typedef struct complex { double real, imag; } complex;
/* Functions */
complex add_complex(complex a, complex b);
complex subtract_complex(complex a, complex b);
complex pow_complex(complex a, complex b);
complex sqrt_complex(complex a);
complex mult_complex(complex a, complex b);
complex divide_complex(complex a, complex b);
complex double_to_complex(double a);
void print_complex(complex a);
#endif