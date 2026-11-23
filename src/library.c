#include <stdio.h>
#include "library.h"

unsigned char library[MAX_LIBRARY][MAX_CHARS] = { { '\0' } };

int write(char method){
    char c;
    unsigned short book;
    unsigned int i = 0;
    
    if      (method == BOOK_1)  book = BOOK_1 - '1'; 
    else if (method == BOOK_2)  book = BOOK_2 - '2'; 
    else if (method == BOOK_3)  book = BOOK_3 - '3';
    else                        return i;

    while((c = getchar()) != EOF) if((i + 1) < MAX_CHARS) library[book][i++] = c;
    
    library[book][i] = '\0';
    clearerr(stdin);
    return i;
}
