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

/* Max function for floats */
float maxf(float a, float b)
{
    if(a >= b)
    {
        return a;
    }
    return b;
}

/* Min function for floats */
float minf(float a, float b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}

/* Max function for ints */
int maxi(int a, int b)
{
    if(a >= b)
    {
        return a;
    }
    return b;
}

/* Min function for ints */
int mini(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}

/* Max function for long longs */
long long maxll(long long a, long long b)
{
    if(a >= b)
    {
        return a;
    }
    return b;
}

/* Min function for long longs */
long long minll(long long a, long long b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}
