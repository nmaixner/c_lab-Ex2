#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyGrep.h"



void check_num_of_arguments(int argc)
{
    if (argc < 3) {
        printf("Not Enough Arguments- Exit The Program\n");
        exit(-1);
    }
    else if (argc > 3) {
        printf("notice you chose to use flags\n");
        return;
    }
    else {
        return;
    }
}


void my_grep(const char *phrase_to_search, const char *file_name)
{
    FILE *file_ptr = fopen(file_name, "r");
    char *line_in_file = NULL;
    size_t line_size = 0;
    int phrase_is_in_line;
    if (NULL == file_ptr) {
        printf("File '%s' did not open- Exit The Program.\n", file_name);
        exit(-1);
    }

    while (getline(&line_in_file, &line_size, file_ptr) != EOF) {
       phrase_is_in_line = check_if_phrase_is_in_line(phrase_to_search, str);
        if (phrase_is_in_line) {
          printf("%s", line_in_file);
      }
    }

    if (NULL != line_in_file) {
        free(line_in_file);
    }
    fclose(file_ptr);
    return;
}






