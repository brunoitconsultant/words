#include "display.h"
#include "input.h"
#include "menu.h"

int main(void) {
    char choice;

    while(1){
        choice = menu();
        if      (choice == EXIT)                        return 0;
        else if (choice == INSERT || choice == APPEND)  write(choice);
        else if (
            choice == DISPLAY_STATS
            || choice == DISPLAY_INPUT
            || choice == DISPLAY_TOKENS
            || choice == DISPLAY_LEXIC)                 display(choice);
        else                                            return 999;
    }
}

