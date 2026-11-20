#include <limits.h>

#define MAX_CHARS INT_MAX

enum input_action{
    INPUT_INSERT            = '1'
    ,INPUT_APPEND           = '2'
};
extern unsigned char input[MAX_CHARS];
int write(char method);
