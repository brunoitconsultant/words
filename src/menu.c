#include <stdio.h>
#include "menu.h"
#include "styling.h" 

char menu(void){
    char t, choice;
    printf(" %s+---------------------------------------------+%s" "\n", T_CYAN,                     T_END  );
    printf(" %s| Pick one of the following operations:       |%s\n",    T_CYAN,                     T_END  );
    printf(" %s+---------------------------------------------+%s\n",    T_CYAN,                     T_END  );
    printf(" %s|  %c. Write new                               |%s\n",   T_CYAN, INSERT,             T_END  );
    printf(" %s|  %c. Append                                  |%s\n",   T_CYAN, APPEND,             T_END  );
    printf(" %s|  -------------------------------------------|%s\n",    T_CYAN,                     T_END  );
    printf(" %s|  %c. Display Statistics                      |%s\n",   T_CYAN, DISPLAY_STATS,      T_END  );
    printf(" %s|  %c. Display Input                           |%s\n",   T_CYAN, DISPLAY_INPUT,      T_END  );
    printf(" %s|  %c. Display Tokens                          |%s\n",   T_CYAN, DISPLAY_TOKENS,     T_END  );
    printf(" %s|  %c. Display Lexic                           |%s\n",   T_CYAN, DISPLAY_LEXIC,      T_END  );
    printf(" %s|  -------------------------------------------|%s\n",    T_CYAN,                     T_END  );
    printf(" %s|  %c  Exit                                    |%s\n",   T_CYAN, EXIT,               T_END  );
    printf(" %s+---------------------------------------------+%s\n\n",  T_CYAN,                     T_END  );
    while((t = getchar()) != '\n') { choice = t; printf("%s",           T_BACKSPACE); }
    return choice;
}
