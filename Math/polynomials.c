#include "polynomials.h"
#include "complex.h"
#include <math.h>

first_order_solutions solve_first_order(double a, double b) {
	first_order_solutions sols;
	if (a == 0) {
		sols.num_sols = 0;
	}
	else {
		sols.num_sols = 1;
		sols.sol0 = (-1 * b) / a;
	}
	return sols;
}

second_order_solutions solve_second_order(double a, double b, double c) {
	second_order_solutions sols; 
	double discriminant; 
	discriminant  = b * b - 4 * a * c;
	if (discriminant < 0) {
		sols.num_sols = 0;
	}
	else if (discriminant == 0) {
		sols.num_sols = 1;
		sols.sol0 = (-1 * b) / (2 * a);
	}
	else {
		sols.num_sols = 2;
		sols.sol0 = ((-1 * b) - sqrt(discriminant)) / (2 * a);
		sols.sol1 = ((-1 * b) + sqrt(discriminant)) / (2 * a);
	}
	return sols;
}

third_order_solutions solve_third_order(double a, double b, double c, double d) {
	third_order_solutions sols;

	/* We apply Cardano's method */
	complex k, q, r, s, t, u, x, y, z, cubic_root;
	cubic_root = double_to_complex((double)1/(double)3);
	q.real = (3 * a * c - b * b) / (9 * a * a);
	q.imag = 0;
	r.real = (9 * a * b * c - 27 * a * a * d - 2 * b * b * b) / (54 * a * a * a);
	r.imag = 0;
	x = pow_complex(q, double_to_complex(3));
	y = pow_complex(r, double_to_complex(2));
	z = add_complex(x, y);
	u = sqrt_complex(z);
	k = add_complex(r, u);
	s = pow_complex(k, cubic_root);
	t = pow_complex(subtract_complex(r, u), cubic_root);
	
	/* We have three solutions, may be imaginary. At least one root is real. */
	sols.num_sols = 3;
	
	/* First solution */
	double alpha = ((double)(b)) / ((double)(3 * a));
	complex beta; /* Second part */
	beta.real = alpha;
	beta.imag = 0;

	sols.sol0 = add_complex(s, subtract_complex(t, beta));
	
	/* General part for second and third solutions */
	complex v, gamma;
	v.real = 0;
	v.imag = sqrt(3) / 2;
	gamma = mult_complex(v, subtract_complex(s, t)); /* Third part */

	complex delta; /* First part */
	delta = mult_complex(double_to_complex((double)(-1)), divide_complex(add_complex(s, t), double_to_complex((double)2)));

	/* Second solution */
	sols.sol1 = add_complex(delta, subtract_complex(gamma, beta));

	/* Third solution */
	sols.sol2 = subtract_complex(delta, add_complex(beta, gamma));
	return sols;
}