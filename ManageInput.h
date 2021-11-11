
#ifndef EX_2_MANAGE_INPUT_H
#define EX_2_MANAGE_INPUT_H
typedef struct Grep_choise {
    int A;
    int A_num;
    int b;
    int c;
    int i;
    int n;
    int v;
    int x;
    int E;
}Grep_choise ;
void identify_grep_options(int argc, char *argv[], struct Grep_choise *choises);
#endif //EX_2_MANAGE_INPUT_H
