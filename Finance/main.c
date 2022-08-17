#include <stdio.h>
#include "finance.h"

int main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    double startval, disc_rate, time_steps;

    startval = 100;
    disc_rate = 0.02;
    time_steps = 1;
    printf("Start val is : %0.2f, disc_rate is %0.2f, time steps is %0.1f\n", startval, disc_rate, time_steps);
    printf("Continuously discounted value is %f\n", discount_cont(startval, disc_rate, time_steps));
    printf("Periodically discounted value is %f\n", discount_period(startval, disc_rate, time_steps));
    return 0;
}