#include <stdio.h>

/* Max function for doubles */
double maxd(double a, double b)
{
    if(a >= b)
    {
        return a;
    }
    return b;
}

/* Min function for doubles */
double mind(double a, double b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}