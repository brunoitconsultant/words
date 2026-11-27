#ifndef CONFIG_H
#define CONFIG_H

#define MAX_DOCS            3
#define MAX_CHARS           200000000
#define MAX_TERMS           50000000
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
    ,DOC_1                  = '1'
    ,DOC_2                  = '2'
    ,DOC_3                  = '3'
    ,STATS                  = '4'
    ,DOCS                   = '5'
    ,TERMS                  = '6'
    ,EXIT                   = '9'
};
#endif
