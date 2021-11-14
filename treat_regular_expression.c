#include "find_match_in_line.h"
#include "manage_input.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REGULAR_CHAR_READING_LENGTH 1

typedef enum _regex_type
{
	REGULAR_CHAR,
	DOT,
	PARENTHESES,
	SQUARE_BRACKETS
} regex_type;

typedef union _content_of_regex {
	char regular_char_content;
	char* parentheses_options[2];
	int square_brackets_range_limits[2];
} RegexContent;

typedef struct _regex {
	regex_type type;
	RegexContent content;
	int len;
	Regex* next;
} Regex;


Regex * new_regex_item(regex_type type, int current_position_on_phrase_to_match, int len_of_regex) {
	Regex* new_item = (Regex*)malloc(sizeof(Regex)); //TODO - don't forget to free this memory!!!
	new_item->type = type;
	//new_item->from = current_position_on_phrase_to_match;
	new_item->len = len_of_regex;
	new_item->next = NULL;
}

regex_type identify_regex_type(char regex_first_char) { // need to handle also '{' and '\'
	regex_type identified_type;
	switch (regex_first_char)
	{
	case '.':
		identified_type = DOT;
		break;

	case '(':
		identified_type = PARENTHESES;
		break;

	case '[':
		identified_type = SQUARE_BRACKETS;
		break;

	default:
		identified_type = REGULAR_CHAR;
		break;
	}
	return identified_type;
}

int get_len_of_regex_parse(char* phrase_to_match, regex_type type) {
	char *pointer_to_phrase = phrase_to_match;
	int string_len_counter = 0;
	while (*pointer_to_phrase != '\0') {
		if (type == REGULAR_CHAR) // first case - only char
		{
			return REGULAR_CHAR_READING_LENGTH;
		}
	}
}

RegexContent get_regex_content(Regex * regex_item, char * pointer_to_phrase) {
	if (regex_item->type == REGULAR_CHAR) {
		regex_item->content.regular_char_content = *pointer_to_phrase;
	}
}

Regex* get_regex_from_phrase(const char * phrase_to_match){
	char* pointer_to_phrase = phrase_to_match;
	int position_in_phrase = 0;
	Regex * regex_start = NULL, *previous_regex = NULL;
	do
	{
		regex_type type = identify_regex_type(*pointer_to_phrase);
		int len_of_fragment = get_len_of_regex_parse(pointer_to_phrase, type);
		Regex* new_parsed_part = new_regex_item(type, position_in_phrase, len_of_fragment);
		
		if (regex_start == NULL) {
			regex_start = new_parsed_part;
		}
		if (previous_regex != NULL) {
			previous_regex->next = new_parsed_part;
		}
		

		position_in_phrase += len_of_fragment;
	} while (*pointer_to_phrase != '\0');
}


bool is_match_on_spot(char* pointer_to_phrase, int len_of_fragment, char* line) {
	int index = 0;
	while (index < len_of_fragment)
	{
		if (*pointer_to_phrase != *line) {
			return false;
		}
		else
		{
			index++;
			pointer_to_phrase++;
			line++;
		}
	}
	return true;
}

bool check_if_phrase_in_line() {

}

// TODO
void free_memory_of_regex_data_structure(){

}

/*
I haven't dealt with the existance of apostrophe in the beginning and end. I suggest it
would be sent to these functions without it, after being verified to exist
*/

/*
add to the function that gets the switches:
if all switch conditions didn't stepped in, and index==(argc-1),
take the last argument to file_name (mark 1 flag for got_file_name)
if got_file_name == 0, make file_pointer to stdin
*/