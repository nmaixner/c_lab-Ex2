#ifndef MY_GREP
#define MY_GREP

void check_num_of_arguments(int argc);
void my_grep(const char *phrase_to_search, const char *file_name);
int check_if_phrase_is_in_line(const char *phrase_to_search, const char *line);

#endif
