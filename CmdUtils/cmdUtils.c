#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h> 

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

/* Function that returns all integers in a specific line of file */
int* get_line_ints(FILE* file, int line_nr) {
    int* buffer; 
    int MAX_INT_LEN = 11;
    int current_int = 0;
    size_t buff_size = 8; /* We start off with memory for 8 ints */  
    buffer = malloc(sizeof(int) * buff_size);

    char* charbuff;
    charbuff = malloc(sizeof(char) * MAX_INT_LEN); /* We use 11 as an integer is at most 11 characters long (-2147483648) */
    
    char c;
    int curr_character = 0;
    int line_ctr = 0;
    /* Skip first couple lines */ 
    while (line_ctr < line_nr) { 
        c = fgetc(file);
        // printf("Getting new char %c, \n");
        if (c == '\n') {
            line_ctr++;
        }
    }

    /* Read line */ 
    while(true) {
        c = fgetc(file);
        if (c == EOF) {
            // printf("End of file reached. Returning...\n");
            buffer[current_int] = atoi(charbuff);
            // printf("Current integer is %d\n", buffer[current_int]);
            free(charbuff);
            current_int++;
            buffer = realloc(buffer, current_int * sizeof(int));
            return buffer;
        } else if (c == '\n') {
            // printf("Newline character encountered.\n");
            buffer[current_int] = atoi(charbuff);
            // printf("Current integer is %d\n", buffer[current_int]);
            free(charbuff);
            current_int++;
            buffer = realloc(buffer, current_int * sizeof(int));
            return buffer;
        } else if (c == ',') {
            /* If a comma is encountered, we are at a new integer and the previous one can be processed */ 
            // printf("Comma encountered. Processing integer\n");
            buffer[current_int] = atoi(charbuff);
            memset(charbuff, 0, sizeof(char) * MAX_INT_LEN);
            // printf("Current integer is %d\n", buffer[current_int]);
            curr_character = 0;
            current_int++;
            if (current_int >= buff_size) {
                buff_size *= 2;
                buffer = realloc(buffer, buff_size * sizeof(int));
                // printf("Buffer about to overflow. Reallocating...\n");
            }
        } else {
            charbuff[curr_character] = c;
            curr_character++;
        }
    }
}

/* Function that returns all floats in a specific line of file */
float* get_line_floats(FILE* file, long long line_nr) {
    float* buffer; 
    static size_t MAX_FLOAT_LEN = 8; /* We start off with 8 chars per float as most floats have less than 8 significant digits. This is static and can be dynamically updated */ 
    long long current_float = 0;
    size_t buff_size = 8; /* We start off with memory for 8 floats */  
    buffer = malloc(sizeof(float) * buff_size);

    char* charbuff;
    charbuff = malloc(sizeof(char) * MAX_FLOAT_LEN); /* Set memory for our char buffer */ 
    
    char c;
    int curr_character = 0; /* Tracks the current character of the float */
    long long line_ctr = 0;

    /* Skip first couple lines */ 
    while (line_ctr < line_nr) { 
        c = fgetc(file);
        // printf("Getting new char %c, \n");
        if (c == '\n') {
            line_ctr++;
        }
    }

    /* Read line */ 
    while(true) {
        c = fgetc(file);
        if (c == EOF) {
            // printf("End of file reached. Returning...\n");
            buffer[current_float] = atof(charbuff);
            // printf("Current float is %0.8f\n", buffer[current_float]);
            free(charbuff);
            current_float++;
            buffer = realloc(buffer, current_float * sizeof(float));
            return buffer;
        } else if (c == '\n') {
            // printf("Newline character encountered.\n");
            buffer[current_float] = atof(charbuff);
            // printf("Current float is %0.8f\n", buffer[current_float]);
            free(charbuff);
            current_float++;
            buffer = realloc(buffer, current_float * sizeof(float));
            return buffer;
        } else if (c == ',') {
            /* If a comma is encountered, we are at a new integer and the previous one can be processed */ 
            // printf("Comma encountered. Processing float\n");
            buffer[current_float] = atof(charbuff);
            memset(charbuff, 0, sizeof(char) * MAX_FLOAT_LEN);
            // printf("Current float is %0.8f\n", buffer[current_float]);
            curr_character = 0;
            current_float++;
            if (current_float >= buff_size) {
                buff_size *= 2;
                buffer = realloc(buffer, buff_size * sizeof(float));
                // printf("Buffer about to overflow. Reallocating...\n");
            }
        } else {
            charbuff[curr_character] = c;
            curr_character++;
            // printf("Current character is %d\n", curr_character);
            if (curr_character >= MAX_FLOAT_LEN) {
                // printf("Char buffer of size %d about to overflow. Reallocating...\n", MAX_FLOAT_LEN);
                MAX_FLOAT_LEN *= 2;
                charbuff = realloc(charbuff, sizeof(char) * MAX_FLOAT_LEN);
            }
        }
    }
}
