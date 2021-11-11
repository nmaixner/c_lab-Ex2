#include "manage_input.h"
#include "find_match_in_line.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
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
int check_if_match_line(const char *phrase_to_search, const char *line, const Grep_choise choises)
{ //will check match with flags
    int match_in_file= NO_MATCHED;
    //creating copy of the line to make changes accoring to flags, withouut harming the line:
    char *copy_line= (char*)malloc((strlen(line)+1)*sizeof(char));
    if (copy_line==NULL)
    {
        printf("problem allocating memory, exiting program");
        exit(-1);
    }
    if (choises.i==0)
    {
        //regular greap -> just send to itai function
        match_in_file=check_if_phrase_is_in_line(phrase_to_search, line);
    }
    else if (choises.i==1)
    {
        printf("i argument was chosen! convert to lower case");
        //write function for i
    }
    if (choises.v==0) //regular line to print
    {
        if (match_in_file==1){
            printf("%s", line);
        }

    }
    else if(choises.v==1)
    {//print only lines that doesnt have the expression
        printf("v flag is on, will print lines withour expression");
        if (match_in_file==0){
            printf("%s", line);
        }
    }
    return match_in_file;



}

