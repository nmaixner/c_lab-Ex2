#include <stdlib.h>
#include <string.h>
#include "ManageInput.h"

my_grep* identify_grep_options(my_grep* my_grep_parameters)
{
    int index = 1;
    bool receive_phrase_from_user = false;
    while (index < argc) {
        if (argv[index] == "-A") {
            my_grep_parameters->print_line_after = true;
            my_grep_parameters->num_of_line_to_print = atoi(argv[index + 1]);
            index++
        }
        else if (argv[i] == "-b") {
            my_grep_parameters->num_of_bits = true;
        }
        else if (argv[i] == "-c") {
            my_grep_parameters->print_only_line_number = true;
        }
        else if (argv[i] == "-i") {
            my_grep_parameters->ignore_capital_letters = true;
        }
        else if (argv[i] == "-n") {
            my_grep_parameters->print_also_line_number = true;
        }
        else if (argv[i] == "-v") {
            my_grep_parameters->print_if_not_in_line = true;
        }
        else if (argv[i] == "-x") {
            my_grep_parameters->print_exclusive = true;
        }
        else if (argv[i] == "-E") {
            my_grep_parameters->special_signs = true;
        }
        else if (receive_phrase_from_user == true) {
            my_grep_parameters->file_name = argv[index];
        }
        else if (receive_phrase_from_user == false) {
            my_grep_parameters->phrase = argv[index];
            receive_phrase_from_user = true;
        }
        index++; 
    }
    return my_grep_parameters;
}

my_grep* initial_grep_parameters() 
{
    my_grep initial_grep = (my_grep*)malloc(sizeof(my_grep));
    initial_grep->phrase = NULL;
    initial_grep->file_name = NULL;
    initial_grep->print_line_after = false;
    initial_grep->num_of_line_to_print = 0;
    initial_grep->num_of_bits = false;
    initial_grep->print_only_line_number = false;
    initial_grep->ignore_capital_letters = false;
    initial_grep->print_also_line_number = false;
    initial_grep->print_if_not_in_line = false;
    initial_grep->print_exclusive = false;
    initial_grep->special_signs = false;
    return initial_grep;
}
