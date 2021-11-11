#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyGrep.h"
#include "ManageInput.h"
#include "FindMatchInLine.h"

#define _GNU_SOURCE
int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    check_num_of_arguments(argc);
    char *phrase_to_search = argv[1];
    char *file_name = argv[2];
    //my_grep(phrase_to_search, file_name);
    struct my_grep choises= {0,0,0,0,0,0,0,0,0};
    //keep all user choises. if choise=1 the option was chosen
    identify_grep_options(argc, argv, &choises); //will get us all aoptions
    printf("%d, %d, %d \n", choises.i , choises.b, choises.c);
    //for debug
    char line[]="ffffff";
    int is_matched=NO_MATCHED;
    is_matched=check_if_match_line(phrase_to_search, line, choises);
    //printf("is matched= %d \n", is_matched);
    //printf("line was: %s \n phrase was %s\n", line, phrase_to_search);


    return 0;
}



