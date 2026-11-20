#include <stdio.h>
#include "input.h"
#include "menu.h"

unsigned char input[MAX_CHARS] = { '\0' };

int write(char method){
    char c;
    unsigned int i = 0;
    
    if      (method == INSERT)  ;
    else if (method == APPEND)  while(input[i] != '\0') i++;
    else                        { return i; }

    while((c = getchar()) != EOF) if((i + 1) < MAX_CHARS) input[i++] = c;
    
    input[i] = '\0';
    clearerr(stdin);
    return i;
}
