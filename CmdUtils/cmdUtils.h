#ifndef CMD_UTILS_H
#define CMD_UTILS_H
void print_line(int len, int count); /* Function that prints a line to the console */
int get_line_count(FILE* file); /* Function that gets the number of lines in a file. If file has no content, we return 0. */
int* get_line_ints(FILE* file, int line_nr); /* Function that returns all integers in a specific line of file */
float* get_line_floats(FILE* file, long long line_nr); /* Function that returns all floats in a specific line of file */
#endif