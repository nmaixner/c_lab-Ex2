
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "manage_input.h"
#include "find_match_in_line.h"

void convert_to_lower(char* str)
{
    int i;
    for(i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    return;
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


int check_if_match_line(my_grep* my_grep, const char *line, int num_line)
{ //will check match with flags
    int match_in_file = NO_MATCHED;
    //creating copy of the line to make changes accoring to flags, withouut harming the line:
    char *copy_line = (char*)malloc((strlen(line)+100)*sizeof(char)); //(strlen(line)+1) made memory leak, dont know why
    if (copy_line == NULL) {
        printf("problem allocating memory, exiting program");
        free(copy_line);
        exit(-1);
    }
    strcpy(copy_line, my_grep->phrase);
    if (my_grep->ignore_capital_letters == true) {
        convert_to_lower(copy_line);
        //convert_to_lower(phrase_to_search);
    }
    match_in_file = check_if_phrase_is_in_line(my_grep->phrase, line);
    if (my_grep->print_only_line_number == true) {//print only lines that doesnt have the expression
        match_in_file = check_if_phrase_is_in_line(my_grep->phrase, line);
    }
    if (my_grep->print_exclusive){ //not working yrt
        int line_index=0;
        int line_len= strlen(line);
        int phrase_len= strlen(my_grep->phrase);
        while (copy_line[line_index]!='\n' &&line_index<=line_len)
            line_index++;
        copy_line[line_index]='\0';
        if (strcmp(copy_line, my_grep->phrase)==0) //exactky equal!
        {
            match_in_file=0;
        }
        else{
            match_in_file=1;
        }

    }
    free(copy_line);
    return match_in_file;
}


int report_line_match(char const *line, my_grep* my_grep, int num_line)
{
    if (check_if_match_line(my_grep, line, num_line) && !my_grep->print_if_not_in_line) {
        return 0;
    }
    else if (!check_if_match_line(my_grep, line, num_line) && my_grep->print_if_not_in_line) {
        return 0;
    }
    else {
        return 1;
    }
}
