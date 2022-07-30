#include <stdio.h>
#include <stdlib.h>

#include "random.h"

int main(int argc, char* argv[])
{
    /* Set random seed */
    srand(1);
    /* Write 25 000 random randd_uniform() numbers to file */
    FILE* f = fopen("rand_uniform.txt", "w");
    for (int i = 0; i < 25000; i++)
    {
        fprintf(f, "%f\n", randd_uniform());
    }
    fclose(f);

    /* Write 25 000 random randd_std_normal() numbers to file */
    FILE* f1 = fopen("rand_std_normal.txt", "w");
    for (int i = 0; i < 25000; i++)
    {
        fprintf(f1, "%f\n", randd_std_norm());
    }
    fclose(f1);

    /* Write 25 000 random randd_std_normal() numbers to file */
    FILE* f2 = fopen("randint.txt", "w");
    for (int i = 0; i < 25000; i++)
    {
        fprintf(f2, "%d\n", randint(5, 10));
    }
    fclose(f2);
    return 0;
}