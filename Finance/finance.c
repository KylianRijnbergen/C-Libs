#include <math.h>

/* Continuously discounts a double. */ 
double discount_cont(double inpval, double disc_rate, double time_steps) {
    if (time_steps == 0) {
        return inpval;
    }
    return inpval * exp(-1 * disc_rate * time_steps);
}

/* Periodically discounts a double. */
double discount_period(double inpval, double disc_rate, double time_steps) {
    if (time_steps == 0) {
        return inpval;
    }
    return inpval * pow((1 - disc_rate), time_steps);
}