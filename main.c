#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "MyGrep.h"
#include <stdbool.h>
#include "manage_input.h"
#include "find_match_in_line.h"

#define _GNU_SOURCE

void my_grep(const char *phrase_to_search, const char *file_name, Grep_choise choises)
{
    FILE *file_ptr = fopen(file_name, "r");
    char *line_in_file = NULL;
    size_t line_size = 0;
    int phrase_is_in_line;
    if (NULL == file_ptr) {
        printf("File '%s' did not open- Exit The Program.\n", file_name);
        exit(-1);
    }
    int num_line=0;
    while (getline(&line_in_file, &line_size, file_ptr) != EOF) {
        //phrase_is_in_line=check_if_match_line(phrase_to_search, line_in_file, choises, num_line);
        phrase_is_in_line=report_line_match(line_in_file, phrase_to_search, choises, num_line);
        if (phrase_is_in_line==0){  //0= expression in line
            printf("%s", line_in_file);
        }
        num_line+=1;
    }
    if (NULL != line_in_file) {
        free(line_in_file);
    }
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
        printf("notice you chose to use flags\n");
        return;
    }
    else {
        return;
    }
}
int main(int argc, char *argv[]) {
    check_num_of_arguments(argc);
    char *phrase_to_search = argv[1];
    char *file_name = argv[2];
    
    
    //my_grep(phrase_to_search, file_name);
    struct Grep_choise choises= {0,0,0,0,0,0,0,0,0};
    //keep all user choises. if choise=1 the option was chosen
    identify_grep_options(argc, argv, &choises); //will get us all aoptions
    printf("printing indexes: %d, %d, %d \n", choises.i , choises.c, choises.v);
    //for debug
    //char line[]="aba ima";
    int is_matched=NO_MATCHED;
    //is_matched=check_if_match_line(phrase_to_search, file_name, choises);
    my_grep(phrase_to_search, file_name, choises);
    
    //printf("is matched= %d \n", is_matched);
    //printf("line was: %s \n phrase was %s\n", line, phrase_to_search);


    return 0;
}



