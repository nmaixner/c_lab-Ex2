#include "manage_input.h"
#include "find_match_in_line.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

FILE* check_file_name(my_grep* my_grep_parametrs)
{
    if (my_grep_parameters->file_name != NULL) {
        FILE* file_ptr = fopen(my_grep_parameters->file_name, "r");
        if (NULL == file_ptr) {
            printf("File '%s' did not open- Exit The Program.\n", my_grep_parameters->file_name);
            exit(-1);
        }
        return file_ptr;
    }
    else {
        return stdin;
    }
}

void string_to_lower_case(char* string)
{
    int index = 0;
    while ((string[index] != '\n') | string[index] != '\0') {
        string[index] = tolower(string[index]);
        index++;
    }
    return;
}

bool check_if_phrase_is_in_line(const char* phrase_to_search, const char* line)
{
    int line_index = 0;
    int phrase_index = 0;
    while (line[line_index] != '\0') {
        while (line[line_index] == phrase_to_search[phrase_index]) {
            line_index++;
            phrase_index++;
            if (phrase_to_search[phrase_index] == '\0') {
                return 1;
            }
        }
        line_index++;
    }
    return 0;
}

void printing_manager(my_grep* my_grep_parametrs, char* line, int num_of_lines, int num_of_bytes) 
{
    if (my_grep_parameters->print_also_line_number) {

}

void grep_manager(my_grep* my_grep_parameters) 
{
    FILE* file_ptr = check_file_name(my_grep_parameters);
    char* line_in_file = NULL;
    size_t line_size = 0;
    bool phrase_is_in_line;
    int num_of_lines = 0;
    int num_of_bytes = 0;
    bool is_line_for_printing;
    bool print_line_number;
    while (getline(&line_in_file, &line_size, file_ptr) != EOF) {
        num_of_lines++;
        if (my_grep_parameters->ignore_capital_letters) {
            string_to_lower_case(my_grep_parameters->phrase);
            string_to_lower_case(line_in_file);
        }
        phrase_is_in_line = check_if_phrase_is_in_line(phrase_to_search, line_in_file);
        if (phrase_is_in_line) {
            is_line_for_printing = true;
        }
        else {
            is_line_for_printing = false;
        }
        if (my_grep_parameters->print_if_not_in_line) {
            if (phrase_is_in_line == true) {
                is_line_for_printing = false;
            }
            else {
                is_line_for_printing = true;
            }
        }
        


    }
    if (NULL != line_in_file) {
        free(line_in_file);
    }
    fclose(file_ptr);
    return;
}
}





int check_if_phrase_is_in_line(const char *phrase_to_search, const char *line)
{ //check regular phrase
    int line_index = 0;
    int phrase_index = 0;
    while (line[line_index] != '\0') {
        while (line[line_index] == phrase_to_search[phrase_index]) {
            line_index++;
            phrase_index++;
            if (phrase_to_search[phrase_index] == '\0') {
                return 1;
            }
        }
        line_index++;
    }
    return 0;
}

