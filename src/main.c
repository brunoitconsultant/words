#include <stdio.h>
#include "config.h"
#include "display.h"
#include "library.h"
#include "lexic.h"
#include "token.h"

char menu(void);

int main(void) {
    char choice;

    while(1){
        choice = menu();
        if      (choice == EXIT)                        return 0;
        else if (
            choice == BOOK_1 
            || choice == BOOK_2 
            || choice == BOOK_3)  
        {   write(choice); 
            tokenize(library); 
            lexicalize(token); 
            display_stats(library);}
        else if(choice  == STATS)                       display_stats(library);
        else if(choice  == INPUT)                       display_input(library);
        else if(choice  == TOKENS)                      display_tokens(token, library);
        else if(choice  == LEXIC)                       display_lexic(lexic);
        else                                            return 999;
    }
}

char menu(void){
    char t, choice;
    display_menu();
    while((t = getchar()) != '\n') { choice = t; printf(T_ERASE_LINE_ABOVE); }
    return choice;
}
