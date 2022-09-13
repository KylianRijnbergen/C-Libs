#ifndef CMD_UTILS_H
#define CMD_UTILS_H
void print_line(int len, int count); /* Function that prints a line to the console */
int get_line_count(FILE* file); /* Function that gets the number of lines in a file. If file has no content, we return 0. */
int* get_line_ints(FILE* file); /* Function that returns all integers in the FIRST line of file */
#endif