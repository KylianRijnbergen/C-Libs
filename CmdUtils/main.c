#include <stdio.h>
#include "cmdUtils.h"

int main(int argc, char* argv);
void test_println(void);
void test_countln(void);

int main(int argc, char* argv) {
    // test_println();
    test_countln();
    return 0;
}

/* Tests the print line function */ 
void test_println(void) {
    int len, count;
    len = 100; 
    count = 5;
    print_line(len, count);
};

/* Tests the count lines function */
void test_countln(void) {
    FILE* file;
    file = fopen("linecount.txt", "r");
    int line_count = get_line_count(file);
    printf("Number of lines in file is %d\n", line_count);
    fclose(file);
}