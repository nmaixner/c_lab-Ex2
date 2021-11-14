
#ifndef EX_2_FIND_MATCH_IN_LINE_H
#define EX_2_FIND_MATCH_IN_LINE_H

#define MATCHED 1
#define NO_MATCHED 0

void convert_to_lower(char* str);
int check_if_phrase_is_in_line(const char* phrase_to_search, const char* line);
int check_if_match_line(my_grep* my_grep, const char* line, int num_line);
int report_line_match(char const* line, my_grep* my_grep, int num_line);


#endif //EX_2_FIND_MATCH_IN_LINE_H
