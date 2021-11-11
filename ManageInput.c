#include <stdlib.h>
#include <string.h>
#include "manage_input.h"

void identify_grep_options(int argc, char *argv[], struct Grep_choise *choises)
{
    int index = 1;
    int input_from_file = 0;
    while (index<argc)
    {
        if (!strcmp(argv[index], "-A"))
        {
            choises->A = 1;
            choises->A_num = atoi(argv[index + 1]);
            index++;
        }
        else if (!strcmp(argv[index], "-b"))
            choises->b = 1;
        else if (!strcmp(argv[index], "-c"))
            choises->c = 1;
        else if (!strcmp(argv[index], "-i"))
            choises->i = 1;
        else if (!strcmp(argv[index], "-n"))
            choises->n = 1;
        else if (!strcmp(argv[index], "-v"))
            choises->v = 1;
        else if (!strcmp(argv[index], "-E"))
            choises->E = 1;
        else if (!strcmp(argv[index], "-x"))
            choises->x = 1;
        index++;
    }
    return;
}
