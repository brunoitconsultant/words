#ifndef TERM_H
#define TERM_H

#include "config.h"
enum schema {
    TERM_DOC            = 0
    ,TERM_SEQ           = 1
    ,TERM_START         = 2
    ,TERM_LENGTH        = 3
    ,TERM_HASH          = 4
    ,TERM_CNT           = 5
    ,TERM_FREQ          = 6
    ,TERM_ATT           = 7
};

extern float term[MAX_DOCS][MAX_TERMS][TERM_ATT];
int extract(unsigned char content[MAX_CHARS], unsigned short doc);
#endif
