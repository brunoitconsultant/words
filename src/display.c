#include <stdio.h>
#include "display.h"

unsigned int pos, page = 1;

void display_menu(){
    printf(" %s+---------------------------------------------+%s" "\n", T_CYAN,                 T_END  );
    printf(" %s| Pick one of the following operations:       |%s\n",    T_CYAN,                 T_END  );
    printf(" %s+---------------------------------------------+%s\n",    T_CYAN,                 T_END  );
    printf(" %s|  %c. Write Book 'The Clockwork Orchard'      |%s\n",   T_CYAN, BOOK_1,         T_END  );
    printf(" %s|  %c. Write Book 'Whispers of the Deep Reef'  |%s\n",   T_CYAN, BOOK_2,         T_END  );
    printf(" %s|  %c. Write Book 'A Guide to Midnight Baking' |%s\n",   T_CYAN, BOOK_3,         T_END  );
    printf(" %s|  -------------------------------------------|%s\n",    T_CYAN,                 T_END  );
    printf(" %s|  %c. Display Library Statistics              |%s\n",   T_CYAN, STATS,          T_END  );
    printf(" %s|  %c. Display Library Content                 |%s\n",   T_CYAN, LIBRARY,        T_END  );
    printf(" %s|  %c. Display Tokens                          |%s\n",   T_CYAN, TOKENS,         T_END  );
    printf(" %s|  %c. Display Lexic                           |%s\n",   T_CYAN, LEXIC,          T_END  );
    printf(" %s|  -------------------------------------------|%s\n",    T_CYAN,                 T_END  );
    printf(" %s|  %c  Exit                                    |%s\n",   T_CYAN, EXIT,           T_END  );
    printf(" %s+---------------------------------------------+%s\n\n",  T_CYAN,                 T_END  );
}

void display_library(unsigned char library[][MAX_CHARS]){
    printf(" %s+-------------+----------------+------+-------+%s\n", T_DARK, T_END);
    printf(" %s| array[n]    | address        | char | value |%s\n", T_DARK, T_END);
    printf(" %s+-------------+----------------+------+-------+%s\n", T_DARK, T_END);  
    for(unsigned short book = 0; book < MAX_LIBRARY; book++){
        for(pos = 0; pos < (page * MAX_PAGESIZE) && library[book][pos] != '\0'; pos++){
            printf(" %s|[%10d] | %-10p | %-4d | %-6s|%s"
                , T_DARK
                , pos
                , (void*)&library[book][pos]
                , library[book][pos]
                , (library[book][pos] == '\n' ? T_CHAR_CR "     " : (char[]){ library[book][pos], '\0' })
                , T_END
            );
            if(pos == (page * MAX_PAGESIZE) - 1){
                printf(" press '+' & ENTER for more.. ");
                unsigned char t;
                while((t = getchar()) != '\n')
                    if(t == '+'){ page++; printf("\r%s%s%s%s\r", T_UP, T_HORIZ_ABS, T_ERASE_LINE, T_DOWN);} else break;
            }else printf("\n");
        }
    }
    printf(" %s+-------------+----------------+------+-------+%s\n\n", T_DARK, T_END);
}

void display_stats(unsigned char library[][MAX_CHARS]){
    unsigned int books = 0, rows = 0, words = 0, chars = 0;
    unsigned char chr, prev = '\0';
    printf(" %s+---------------------------------------------+%s\n", T_DARK, T_END);
    printf(" %s| Stats                                       |%s\n", T_DARK, T_END);
    printf(" %s+---------------------------------------------+%s\n", T_DARK, T_END);
    for(unsigned short book = 0; book < MAX_LIBRARY; book++){
        if(library[book][0] != '\0') books++;
        for(unsigned int c = 0; (chr = library[book][c]) != '\0'; c++){
            if(chr == '\n') rows++; else chars++;
            if(
                ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
                && (prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z'))
            ) ++words;
            prev = chr;
        }
    }
    printf(" %s| Books: %-36d |%s\n %s| Chars: %-36d |%s\n %s| Rows:  %-36d |%s\n %s| Words: %-36d |%s\n", T_DARK, books, T_END, T_DARK, chars, T_END, T_DARK, rows, T_END, T_DARK, words, T_END);
    printf(" %s+---------------------------------------------+%s\n\n", T_DARK, T_END);
}

void display_tokens(unsigned int token[][4], unsigned char input[]){
    printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
    printf(" %s| token[n]    | value            | hash[djb2] |%s\n", T_DARK, T_END);
    printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
    for(pos = 0; pos < (page * MAX_PAGESIZE) && token[pos][2] != '\0'; pos++){
        printf(" %s|[%10d] | ", T_DARK, token[pos][0]);
        for(unsigned short i = token[pos][1]; i < (token[pos][1] + token[pos][2]); i++){ printf("%c", input[i]); }
        for(unsigned short i = 0; i < (17 - token[pos][2]); i++){ printf(" "); } printf("|%s", T_END);
        printf("%s %-10u |%s", T_DARK, token[pos][3], T_END);
        if(pos == (page * MAX_PAGESIZE) - 1){
            printf(" press '+' & ENTER for more.. ");
            unsigned char t;
            while((t = getchar()) != '\n')
                if(t == '+'){ page++; printf("\r%s%s%s%s\r", T_UP, T_HORIZ_ABS, T_ERASE_LINE, T_DOWN);} else break;
        }else printf("\n");
    }
    printf(" %s+-------------+------------------+------------+%s\n\n", T_DARK, T_END);
}

void display_lexic(unsigned int lexic[][2]){
    printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
    printf(" %s| lexic[n]    | token[hash]      | count      |%s\n", T_DARK, T_END);
    printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
    for(pos = 0; pos < MAX_WORDS; pos++)
        if(lexic[pos][1] > 0)
            printf(" %s|[%10d] | %-16u | %-10u |%s\n", T_DARK, pos, lexic[pos][0], lexic[pos][1], T_END);
    printf(" %s+-------------+------------------+------------+%s\n\n", T_DARK, T_END);
}

