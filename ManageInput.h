#ifndef MANAGE_INPUT_H
#define MANAGE_INPUT_H

#include <stdbool.h>

typedef struct myGrep {
	char* phrase;
	char* file_name;
	bool print_line_after; // True if -A
	int num_of_line_to_print; //num for -A
	bool num_of_bits; // True if -b
	bool print_only_line_number; // True if -c
	bool ignore_capital_letters; // True if -i
	bool print_also_line_number; // True if -n
	bool print_if_not_in_line; // True if -v
	bool print_exclusive; // True if -x
	bool special_signs; // True if -E
}my_grep;

my_grep* identify_grep_options(my_grep* my_grep_parameters);
my_grep* initial_grep_parameters();

#endif // !MANAGE_INPUT_H
