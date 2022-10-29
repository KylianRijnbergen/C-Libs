#include <stdio.h>
#include <math.h>
#include "complex.h"
#include "polynomials.h"

int main(int argc, char* argv) {
	complex a, b, c;
	a.real = 2;
	a.imag = 1;
	b.real = 0.5;
	b.imag = 0;
	
	c = add_complex(a, b);
	// printf("The value of c is %0.2f + %0.2fi\n", c.real, c.imag);

	complex d;
	d = pow_complex(a, b);
	// printf("The value of d is %f + %fi\n", d.real, d.imag);

	complex e;
	e = sqrt_complex(a);
	// printf("The value of e is %f + %fi\n", e.real, e.imag);

	complex f = { -0.5, (sqrt(3)/2)};
	complex g, h;
	g.real = 3;
	g.imag = 0;
	h = pow_complex(f, g);
	// printf("F cubed is %f, %fi\n", h.real, h.imag);

	complex i = { 3, 2 };
	complex k = { 2, 1 };
	complex j = divide_complex(i, k);
	// printf("i/2 is %f, %fi \n", j.real, j.imag);


	double alph, bet, gam, delt;
	alph = 2;
	bet = 8;
	gam = 13;
	delt = 6;
	// printf("1st order: X = %f\n", solve_first_order(alph, bet).sol0);
	// printf("2nd order: X = %f, or %f\n", solve_second_order(alph, bet, gam).sol0, solve_second_order(alph, bet, gam).sol1);
	third_order_solutions sols;
	sols = solve_third_order(alph, bet, gam, delt);
	printf("3rd order: X = %f + %fi or X = %f + %fi or X = %f + %fi\n", sols.sol0.real, sols.sol0.imag, sols.sol1.real, sols.sol1.imag, sols.sol2.real, sols.sol2.imag);
	return 0;
}