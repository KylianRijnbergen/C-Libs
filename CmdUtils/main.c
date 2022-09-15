#include <stdio.h>
#include "cmdUtils.h"

int main(int argc, char* argv);
void test_println(void);
void test_countln(void);
void test_get_line_ints(void); 
void test_get_line_floats(void);

int main(int argc, char* argv) {
    // test_println();
    // test_countln();
    // test_get_line_ints();
    test_get_line_floats();
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

void test_get_line_ints(void) {
    FILE* file;
    file = fopen("getlineints.txt", "r");
    int* ints;
    ints = get_line_ints(file, 2);
    printf("\n\n");
    for (int i = 0; i < 36; i++) { /* Our testfile has 36 ints */
        printf("%dth integer is %d\n", i, ints[i]);
    }
}

void test_get_line_floats(void) {
    FILE* file;
    file = fopen("getlinefloats.txt", "r");
    float* floats;
    floats = get_line_floats(file, 0);
    for (int i = 0; i < 8; i++) {
        printf("%dth float is %0.8f\n", i, floats[i]);
    }
    fclose(file);
}
