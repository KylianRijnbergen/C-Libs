#include <stdio.h>
#include <stdlib.h>

#include "random.h"

int main(int argc, char* argv[])
{
    /* Set random seed */
    srand(1);
    /* Write 25 000 random numbers to file */
    FILE* f = fopen("rand_uniform.txt", "w");
    for (int i = 0; i < 25000; i++)
    {
        fprintf(f, "%f\n", randd_uniform());
    }
    fclose(f);
    return 0;
}