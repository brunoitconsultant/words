#include "djb2.h"
#include "term.h"

float term[MAX_DOCS][MAX_TERMS][TERM_ATT] = { { { '\0' } } };
static void tf(float term[][TERM_ATT]);
static void idf(float term[][TERM_ATT]);

int extract(unsigned char content[MAX_CHARS], unsigned short doc){
    unsigned char chr, prev = '\0';
    unsigned int seq = 0;
    for(unsigned int i = 0; ((chr = content[i]) != '\0'); i++){
        if(
            ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
            && ((prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z')))
        ){
            if(seq < (MAX_TERMS - 1)){
                term[doc][seq][TERM_DOC]        = doc;
                term[doc][seq][TERM_SEQ]        = seq;
                term[doc][seq][TERM_START]      = i;
                term[doc][seq][TERM_LENGTH]     = 1;
                term[doc][seq][TERM_CNT]        = 0;
                term[doc][seq][TERM_BOOK_CNT]   = 0;
                term[doc][seq][TERM_FREQ]       = 0;
                seq++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')){
            term[doc][seq-1][TERM_LENGTH]++;
            term[doc][seq-1][TERM_HASH] = djb2(content, term[doc][seq-1][TERM_START], term[doc][seq-1][TERM_LENGTH]);
        }
        prev = chr;
    }
    term[doc][seq][TERM_LENGTH] = '\0';
    tf(term[doc]);
    idf(term[doc]);
    return 0;
}

static void tf(float term[][TERM_ATT]){ 
    unsigned int max = 0;
    for(unsigned int t = 0; t < (MAX_TERMS - 1) && term[t][TERM_LENGTH] != '\0'; t++) max++;
    for(unsigned int t = 0; t < max; t++){
        for(unsigned int i = 0; i < max; i++)
            if(term[t][TERM_HASH] == term[i][TERM_HASH]) term[t][TERM_CNT]++;
        term[t][TERM_FREQ] = term[t][TERM_CNT] / max;
    }
}

static void idf(float term[][TERM_ATT]){
    /*unsigned int max = 0;
    for(unsigned int t = 0; t < (MAX_TERMS - 1) && term[t][TERM_LENGTH] != '\0'; t++) max++;
    for(unsigned int t = 0; t < max; t++){
        for(unsigned int i = 0; i < max; i++)
            if(term[t][TERM_HASH] == term[i][TERM_HASH]) term[t][TERM_CNT]++;
        term[t][TERM_FREQ] = term[t][TERM_CNT] / max;
    }*/
}
