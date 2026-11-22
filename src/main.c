#include <stdio.h>
#include "display.h"
#include "input.h"
#include "lexic.h"
#include "token.h"

char menu(void);

int main(void) {
    char choice;

    while(1){
        choice = menu();
        if      (choice == EXIT)                            return 0;
        else if (choice == INSERT || choice == APPEND)      write(choice);
        else if (choice == TOKENIZE)                        tokenize(input);
        else if (choice == LEXICALIZE)                      lexicalize(token);
        else if (
            choice      == STATS
            || choice   == INPUT
            || choice   == TOKENS
            || choice   == LEXIC)                           display(choice);
        else                                                return 999;
    }
}

char menu(void){
    char t, choice;
    display(SHOW);
    while((t = getchar()) != '\n') { choice = t; printf("\033[1A\r\033[K"); }
    return choice;
}
