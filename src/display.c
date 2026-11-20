#include <stdio.h>
#include "display.h"
#include "menu.h"
#include "input.h"
#include "token.h"
#include "lexic.h"

#define MAX_PAGESIZE    50
#define T_CYAN          "\033[44m\033[37m"
#define T_DARK          "\033[38;5;51;48;5;234m"
#define T_END           "\033[0m"
#define T_CHAR_CR       "\xE2\x86\xB5"
#define T_BACKSPACE     "\033[1A\r\033[K"
#define T_UP            "\033[1A"
#define T_HORIZ_ABS     "\033[49G"
#define T_ERASE_LINE    "\033[K"
#define T_DOWN          "\033[1B"

int display(char choice){
    unsigned int pos, page = 1;

    if(input[0] == '\0') return 1;
    else if(choice == DISPLAY_INPUT){
        printf(" %s+-------------+----------------+------+-------+%s\n", T_DARK, T_END);
        printf(" %s| array[n]    | address        | char | value |%s\n", T_DARK, T_END);
        printf(" %s+-------------+----------------+------+-------+%s\n", T_DARK, T_END);
        for(pos = 0; pos < (page * MAX_PAGESIZE) && input[pos] != '\0'; pos++){
            printf(" %s|[%10d] | %-10p | %-4d | %-6s|%s"
                , T_DARK
                , pos
                , (void*)&input[pos]
                , input[pos]
                , (input[pos] == '\n' ? T_CHAR_CR "     " : (char[]){ input[pos], '\0' })
                , T_END
            );
            if(pos == (page * MAX_PAGESIZE) - 1){
                printf(" press '+' & ENTER for more.. ");
                unsigned char t;
                while((t = getchar()) != '\n')
                    if(t == '+'){ page++; printf("\r%s%s%s%s\r", T_UP, T_HORIZ_ABS, T_ERASE_LINE, T_DOWN);} else break;
            }else printf("\n");
        }
        printf(" %s+-------------+----------------+------+-------+%s\n\n", T_DARK, T_END);
        return 0;
    }else if(choice == DISPLAY_STATS){
        unsigned int rows = 0, words = 0, chars;
        unsigned char chr, prev = '\0';
        printf(" %s+---------------------------------------------+%s\n", T_DARK, T_END);
        printf(" %s| Stats                                       |%s\n", T_DARK, T_END);
        printf(" %s+---------------------------------------------+%s\n", T_DARK, T_END);
        for(chars = 0; (chr = input[chars]) != '\0'; chars++){
            if(chr == '\n') rows++;
            if(
                ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
                && (prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z'))
            ) ++words;
            prev = chr;
        }
        printf(" %s| Chars: %-36d |%s\n %s| Rows:  %-36d |%s\n %s| Words: %-36d |%s\n", T_DARK, chars, T_END, T_DARK, rows, T_END, T_DARK, words, T_END);
        printf(" %s+---------------------------------------------+%s\n\n", T_DARK, T_END);
        return 0;
    }else if(choice == DISPLAY_TOKENS){
        tokenize();
        printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
        printf(" %s| token[n]    | value            | hash[djb2] |%s\n", T_DARK, T_END);
        printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
        for(pos = 0; pos < (page * MAX_PAGESIZE) && token[pos][2] != '\0'; pos++){
            printf(" %s|[%10d] | ", T_DARK, token[pos][0]);
            for(unsigned short i = token[pos][1]; i < (token[pos][1] + token[pos][2]); i++){ printf("%c", input[i]); }
            for(unsigned short i = 0; i < (17 - token[pos][2]); i++){ printf(" "); } printf("|%s", T_END);
            printf(" %s%-10u |%s", T_DARK, token[pos][3], T_END);
            if(pos == (page * MAX_PAGESIZE) - 1){
                printf(" press '+' & ENTER for more.. ");
                unsigned char t;
                while((t = getchar()) != '\n')
                    if(t == '+'){ page++; printf("\r%s%s%s%s\r", T_UP, T_HORIZ_ABS, T_ERASE_LINE, T_DOWN);} else break;
            }else printf("\n");
        }
        printf(" %s+-------------+------------------+------------+%s\n\n", T_DARK, T_END);
        return 0;
    }else if(choice == DISPLAY_LEXIC){
        tokenize();
        lexicalize();
        printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
        printf(" %s| lexic[n]    | token[hash]      | count      |%s\n", T_DARK, T_END);
        printf(" %s+-------------+------------------+------------+%s\n", T_DARK, T_END);
        for(pos = 0; pos < MAX_WORDS; pos++)
            if(lexic[pos][1] > 0)
                printf(" %s|[%10d] | %-16u | %-10u |%s\n", T_DARK, pos, lexic[pos][0], lexic[pos][1], T_END);
        printf(" %s+-------------+------------------+------------+%s\n\n", T_DARK, T_END);
        return 0;

    }else return 999;
}
