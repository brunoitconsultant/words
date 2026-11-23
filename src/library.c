#include <stdio.h>
#include "library.h"

unsigned char library[MAX_CHARS] = { '\0' };

int write(char method){
    char c;
    unsigned int i = 0;
    
    if  (
        method == BOOK_1 
        || method == BOOK_2 
        || method == BOOK_3)    ;
    else                        return i;

    while((c = getchar()) != EOF) if((i + 1) < MAX_CHARS) library[i++] = c;
    
    library[i] = '\0';
    clearerr(stdin);
    return i;
}
