#include <stdio.h>
#include "config.h"
#include "display.h"
#include "document.h"
#include "term.h"

char menu(void);

int main(void) {
    char choice;
    unsigned short id; 

    while(1){
        choice = menu();
        if      (choice     == EXIT     )   return 0;
        else if (choice     == DOC_1    )   { id = DOC_1 - '1' ; upload(choice); extract(document[id], id); compute_idf(term), display_stats(document); }
        else if (choice     == DOC_2    )   { id = DOC_2 - '1' ; upload(choice); extract(document[id], id); compute_idf(term); display_stats(document); }
        else if (choice     == DOC_3    )   { id = DOC_3 - '1' ; upload(choice); extract(document[id], id); compute_idf(term); display_stats(document); }
        else if (choice     == STATS    )   display_stats   (document);
        else if (choice     == DOCS     )   display_library (document);
        else if (choice     == TFIDF    )   display_tfidf   (term, document);
        else                                return 999;
    }
}

char menu(void){
    char t, choice;
    display_menu();
    while((t = getchar()) != '\n') { choice = t; printf(T_ERASE_LINE_ABOVE); }
    return choice;
}
