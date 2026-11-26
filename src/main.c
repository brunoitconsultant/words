#include <stdio.h>
#include "config.h"
#include "display.h"
#include "document.h"
#include "lexic.h"
#include "token.h"

char menu(void);

int main(void) {
    char choice;
    unsigned short id; 

    while(1){
        choice = menu();
        if      (choice     == EXIT     )   return 0;
        else if (choice     == DOC_1    )   { id = DOC_1 - '1' ; upload(choice); tokenize(document[id], id); lexicalize(token, id); display_stats(document); }
        else if (choice     == DOC_2    )   { id = DOC_2 - '1' ; upload(choice); tokenize(document[id], id); lexicalize(token, id); display_stats(document); }
        else if (choice     == DOC_3    )   { id = DOC_3 - '1' ; upload(choice); tokenize(document[id], id); lexicalize(token, id); display_stats(document); }
        else if (choice     == STATS    )   display_stats(document);
        else if (choice     == DOCS     )   display_library(document);
        else if (choice     == TOKENS   )   display_tokens(token, document);
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
