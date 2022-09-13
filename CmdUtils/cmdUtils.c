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

/* Function that gets the number of lines in a file. If file has no content, we return 0. */
int get_line_count(FILE* file) {
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    int linecount = 0;
    char c; 
    do {
        c = fgetc(file);
        if (c == '\n') {
            linecount++;
        }
    } while (c != EOF);
    return linecount;
}