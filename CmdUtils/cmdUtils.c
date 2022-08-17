#include <stdio.h>

/* Function that prints a line to the console */
void print_line(int len, int count)
{
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < len; j++) {
            printf("_");
        }
        printf("\n");
    }
}