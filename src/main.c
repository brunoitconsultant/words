#include <stdio.h>
#include "config.h"
#include "display.h"
#include "library.h"
#include "lexic.h"
#include "token.h"

char menu(void);

int main(void) {
    char choice;
    unsigned short book;

    while(1){
        choice = menu();
        if      (choice     == EXIT     )   return 0;
        else if (choice     == BOOK_1   )   { book = BOOK_1 - '1' ; write(choice); tokenize(library[book]); lexicalize(token); display_stats(library); }
        else if (choice     == BOOK_2   )   { book = BOOK_2 - '1' ; write(choice); tokenize(library[book]); lexicalize(token); display_stats(library); }
        else if (choice     == BOOK_3   )   { book = BOOK_3 - '1' ; write(choice); tokenize(library[book]); lexicalize(token); display_stats(library); }
        else if (choice     == STATS    )   display_stats(library);
        else if (choice     == LIBRARY  )   display_library(library);
        else if (choice     == TOKENS   )   display_tokens(token, library[book]);
        else if (choice     == LEXIC    )   display_lexic(lexic);
        else                                return 999;
    }
}

char menu(void){
    char t, choice;
    display_menu();
    while((t = getchar()) != '\n') { choice = t; printf(T_ERASE_LINE_ABOVE); }
    return choice;
}
