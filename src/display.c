#include <stdio.h>
#include "display.h"

unsigned int pos, page = 1;

void display_menu(){
    printf(" %s+---------------------------------------------+%s" "\n", T_CYAN,                 T_END  );
    printf(" %s| Pick one of the following operations:       |%s\n",    T_CYAN,                 T_END  );
    printf(" %s+---------------------------------------------+%s\n",    T_CYAN,                 T_END  );
    printf(" %s|  %c. Upload Doc 1                            |%s\n",   T_CYAN, DOC_1,          T_END  );
    printf(" %s|  %c. Upload Doc 2                            |%s\n",   T_CYAN, DOC_2,          T_END  );
    printf(" %s|  %c. Upload Doc 3                            |%s\n",   T_CYAN, DOC_3,          T_END  );
    printf(" %s|  -------------------------------------------|%s\n",    T_CYAN,                 T_END  );
    printf(" %s|  %c. Print Statistics                        |%s\n",   T_CYAN, STATS,          T_END  );
    printf(" %s|  %c. Print Documents                         |%s\n",   T_CYAN, DOCS,           T_END  );
    printf(" %s|  %c. Print TF                                |%s\n",   T_CYAN, TF,             T_END  );
    printf(" %s|  -------------------------------------------|%s\n",    T_CYAN,                 T_END  );
    printf(" %s|  %c  Exit                                    |%s\n",   T_CYAN, EXIT,           T_END  );
    printf(" %s+---------------------------------------------+%s\n\n",  T_CYAN,                 T_END  );
}

void display_library(unsigned char documents[][MAX_CHARS]){
    printf(" %s+-------------+----------------+------+-------+%s\n", T_DARK, T_END);
    printf(" %s| array[n]    | address        | char | value |%s\n", T_DARK, T_END);
    printf(" %s+-------------+----------------+------+-------+%s\n", T_DARK, T_END);  
    for(unsigned short id = 0; id < MAX_DOCS; id++){
        for(pos = 0; pos < (page * MAX_PAGESIZE) && documents[id][pos] != '\0'; pos++){
            printf(" %s|[%10d] | %-10p | %-4d | %-6s|%s"
                , T_DARK
                , pos
                , (void*)&documents[id][pos]
                , documents[id][pos]
                , (documents[id][pos] == '\n' ? T_CHAR_CR "     " : (char[]){ documents[id][pos], '\0' })
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

void display_stats(unsigned char documents[][MAX_CHARS]){
    unsigned int docs = 0, rows = 0, words = 0, chars = 0;
    unsigned char chr, prev = '\0';
    printf(" %s+---------------------------------------------+%s\n", T_DARK, T_END);
    printf(" %s| Stats                                       |%s\n", T_DARK, T_END);
    printf(" %s+---------------------------------------------+%s\n", T_DARK, T_END);
    for(unsigned short id = 0; id < MAX_DOCS; id++){
        if(documents[id][0] != '\0') docs++;
        for(unsigned int c = 0; (chr = documents[id][c]) != '\0'; c++){
            if(chr == '\n') rows++; else chars++;
            if(
                ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
                && (prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z'))
            ) ++words;
            prev = chr;
        }
    }
    printf(" %s| Docs:  %-36d |%s\n %s| Chars: %-36d |%s\n %s| Rows:  %-36d |%s\n %s| Words: %-36d |%s\n", T_DARK, docs, T_END, T_DARK, chars, T_END, T_DARK, rows, T_END, T_DARK, words, T_END);
    printf(" %s+---------------------------------------------+%s\n\n", T_DARK, T_END);
}

void display_tf(float term[][MAX_TERMS][7], unsigned char document[][MAX_CHARS]){
    printf(" %s+--------+----------+------------+------------+%s\n", T_DARK, T_END);
    printf(" %s| doc[n] | term[n]  | value      | term freq. |%s\n", T_DARK, T_END);
    printf(" %s+--------+----------+------------+------------+%s\n", T_DARK, T_END);
    for(unsigned short doc = 0; doc < MAX_DOCS; doc++){
        for(pos = 0; pos < (page * MAX_PAGESIZE) && term[doc][pos][3] != '\0'; pos++){
            printf(" %s| [%4d] | [%6.0f] | ", T_DARK, doc, term[doc][pos][0]);
            for(unsigned short i = term[doc][pos][2]; i < (term[doc][pos][2] + term[doc][pos][3]); i++){ printf("%c", document[doc][i]); }
            for(unsigned short i = 0; i < (11 - term[doc][pos][3]); i++){ printf(" "); } printf("|%s", T_END);
            printf("%s %-10.8f |%s", T_DARK, term[doc][pos][6], T_END);
            if(pos == (page * MAX_PAGESIZE) - 1){
                printf(" press '+' & ENTER for more.. ");
                unsigned char t;
                while((t = getchar()) != '\n')
                    if(t == '+'){ page++; printf("\r%s%s%s%s\r", T_UP, T_HORIZ_ABS, T_ERASE_LINE, T_DOWN);} else break;
            }else printf("\n");
        }
    }
    printf(" %s+---------+---------+------------+------------+%s\n\n", T_DARK, T_END);
}
