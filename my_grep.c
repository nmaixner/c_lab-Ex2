#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "MyGrep.h"
#include <stdbool.h>
#include "ManageInput.h"
#include "find_match_in_line.h"

#define _GNU_SOURCE
size_t getline_my(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL) {
        return -1;
    }
    if (stream == NULL) {
        return -1;
    }
    if (n == NULL) {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) {
        return -1;
    }
    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) {
            free(bufptr);
            return -1;

        }
        size = 128;
    }
    p = bufptr;
    while(c != EOF) {
        if ((p - bufptr) > (size - 1)) {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n') {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}
void handle_prints(char const* line, my_grep* my_grep, int num_line, int phrase_is_in_line, int num_bits){
    if (phrase_is_in_line==0 && my_grep->print_only_line_number) {
        printf("%d \n", num_line);//0= expression in line
    }
    else if (phrase_is_in_line==0 && my_grep->num_of_bits) {
            printf("%d: %s", num_bits, line);//0= expression in line
        }
    else if (phrase_is_in_line==0 && my_grep->print_also_line_number) {
        printf("%d: %s\n", num_line, line);//0= expression in line
    }
    else if(phrase_is_in_line==0) {
        printf("%s", line);
    }
    return;
}
void activate_grep (my_grep* my_grep)
{
    char *buf = NULL; /*malloc(10);*/
    int bufSize = 0; /*10;*/
    FILE *file_ptr=NULL;
    file_ptr = fopen(my_grep->file_name, "r");
    char *line_in_file = NULL;
    size_t line_size = 0;
    int phrase_is_in_line;
    if (NULL == file_ptr) {
        printf("File '%s' did not open- Exit The Program.\n", my_grep->file_name);
        free(file_ptr);
        free(my_grep);
        exit(-1);
        ;
    }
    int print_lines_after=0;
    int num_line = 1;
    int num_bits=0;
    while (getline(&line_in_file, &line_size, file_ptr) != EOF) {
        //phrase_is_in_line=check_if_match_line(phrase_to_search, line_in_file, choises, num_line);
        phrase_is_in_line = report_line_match(line_in_file, my_grep, num_line);
        handle_prints(line_in_file, my_grep, num_line, phrase_is_in_line, num_bits);
        num_bits=num_bits+strlen(line_in_file);
        num_line+=1;
    }
    if (NULL != line_in_file) {
        free(line_in_file);
    }
    /* try to handle stdin- doesnt work good
    if (file_ptr==NULL){
        while (getline_my(&line_in_file, &line_size, stdin) != EOF) {
            //phrase_is_in_line=check_if_match_line(phrase_to_search, line_in_file, choises, num_line);
            phrase_is_in_line = report_line_match(line_in_file, my_grep, num_line);
            handle_prints(line_in_file, my_grep, num_line, phrase_is_in_line, num_bits);
            num_bits = num_bits + strlen(line_in_file);
            num_line += 1;
        }
    }
    */
    fclose(file_ptr);
    return;
}


void check_num_of_arguments(int argc)
{
    if (argc < 3) {
        printf("Not Enough Arguments- Exit The Program\n");
        exit(-1);
    }
    else if (argc > 3) {
        //printf("notice you chose to use flags\n");
        return;
    }
    else {
        return;
    }
}


int main(int argc, char *argv[])
{
    check_num_of_arguments(argc);

    //my_grep(phrase_to_search, file_name);
    my_grep* new_grep = initial_grep_parameters();
    //keep all user choises. if choise=1 the option was chosen
    new_grep = identify_grep_options(new_grep, argc, argv); //will get us all aoptions
    //printf("printing indexes: %d, %d, %d \n", new_grep->ignore_capital_letters, new_grep->print_only_line_number, new_grep->print_if_not_in_line);
    activate_grep(new_grep);
    free(new_grep);



    return 0;
}



