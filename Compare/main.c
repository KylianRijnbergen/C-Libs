#include <stdio.h>
#include "compare.h"

int main(int argc, char* argv);

int main(int argc, char* argv) {
    double low, high;
    
    low = 1;
    high = 100;

    printf("Lowest between low (%f) and high (%f) is (%f)\n", low, high, mind(low, high));
    printf("Highest between low (%f) and high (%f) is (%f)\n", low, high, maxd(low, high));
    return 0;
}