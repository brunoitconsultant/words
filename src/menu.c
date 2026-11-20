#include <stdio.h>
#include "display.h"
#include "menu.h"

char menu(void){
    char t, choice;
    display(MENU_SHOW);
    while((t = getchar()) != '\n') { choice = t; printf("\033[1A\r\033[K"); }
    return choice;
}
