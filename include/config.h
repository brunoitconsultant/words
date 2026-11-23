#ifndef CONFIG_H
#define CONFIG_H

#include <limits.h>

#define MAX_LIBRARY         3
#define MAX_CHARS           INT_MAX
#define MAX_TOKENS          200000000
#define MAX_WORDS           1000000
#define MAX_PAGESIZE        40

#define T_CYAN              "\033[44m\033[37m"
#define T_DARK              "\033[38;5;51;48;5;234m"
#define T_END               "\033[0m"
#define T_CHAR_CR           "\xE2\x86\xB5"
#define T_UP                "\033[1A"
#define T_HORIZ_ABS         "\033[49G"
#define T_ERASE_LINE        "\033[K"
#define T_ERASE_LINE_ABOVE  "\033[1A\r\033[K"
#define T_DOWN              "\033[1B"

enum menu {
    SHOW                    = '0'
    ,BOOK_1                 = '1'
    ,BOOK_2                 = '2'
    ,BOOK_3                 = '3'
    ,STATS                  = '5'
    ,INPUT                  = '6'
    ,TOKENS                 = '7'
    ,LEXIC                  = '8'
    ,EXIT                   = '9'
};
#endif
