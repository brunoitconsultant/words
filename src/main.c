#include <stdio.h>
#include "menu.h"
#include "input.h"
#include "display.h"

int main() {
    char choice;
    while(1){
        choice = menu();
        if      (choice              == EXIT)               return 0;
        else if (choice              == INSERT)             write(choice);
        else if (choice              == APPEND)             write(choice);
        else if (choice              == DISPLAY_STATS)      display(choice);
        /*else if (choice              == DISPLAY_INPUT)      display(choice);
        else if (choice              == DISPLAY_TOKENS)     display(choice);
        else if (choice              == DISPLAY_LEXIC)      display(choice);*/
        else                                                printf(" \"%c\" is an invalid option\n", choice);
    }
}

