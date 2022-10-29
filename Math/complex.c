#include <math.h>
#include "complex.h"
#include <stdio.h>

static double get_arg(complex a);
static double get_magnitude(complex a);

/* Complex addition */
complex add_complex(complex a, complex b) {
	complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}

/* Complex subtraction */
complex subtract_complex(complex a, complex b) {
	complex c;
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	return c;
}

complex pow_complex(complex base, complex exponent) {
	complex compl_num;
	if (base.real == 0 && base.imag == 0) {
		compl_num.real = 0;
		compl_num.imag = 0;
		return compl_num;
	}
	if (exponent.real == 0 && exponent.imag == 0) {
		compl_num.real = 1;
		compl_num.imag = 0;
		return compl_num;
	}
	double r, theta;
	double alpha;
	double scalar;

	r = get_magnitude(base); /* Magnitude */
	theta = get_arg(base); /* Phase angle */

	alpha = exponent.real * theta + exponent.imag * log(r);
	scalar = pow(r, exponent.real) * exp(-1 * exponent.imag * theta);
	/* Real part */
	compl_num.real = scalar * cos(alpha);

	/* Imaginary part */
	compl_num.imag = scalar * sin(alpha);
	return compl_num;
}

static double get_arg(complex a) {
	return atan2(a.imag, a.real);
}

static double get_magnitude(complex a) {
	return sqrt(pow(a.real, 2) + pow(a.imag, 2));
}

complex sqrt_complex(complex a) {
	complex b = { 0.5, 0 };
	return pow_complex(a, b);
}

complex mult_complex(complex a, complex b) {
	complex c;
	c.real = a.real * b.real - a.imag * b.imag;
	c.imag = a.imag * b.real + a.real * b.imag;
	return c;
}

complex divide_complex(complex a, complex b) {
	complex c;
	c.real = (a.real * b.real + a.imag * b.imag) / (pow(b.real, 2) + pow(b.imag, 2));
	c.imag = (a.imag * b.real - a.real * b.imag) / (pow(b.real, 2) + pow(b.imag, 2));
	return c;
}

complex double_to_complex(double a) {
	complex c = { a, 0 };
	return c;
}

void print_complex(complex a) {
	printf(" Value: %f + %fi\n", a.real, a.imag);
}