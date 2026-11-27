#include "djb2.h"
#include "term.h"

float term[MAX_DOCS][MAX_TERMS][7] = { { { '\0' } } };
static void tf(float term[][7]);

int extract(unsigned char content[MAX_CHARS], unsigned short doc){
    unsigned char chr, prev = '\0';
    unsigned int seq = 0;
    for(unsigned int i = 0; ((chr = content[i]) != '\0'); i++){
        if(
            ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
            && ((prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z')))
        ){
            if(seq < (MAX_TERMS - 1)){
                term[doc][seq][0] = seq;
                term[doc][seq][1] = doc;
                term[doc][seq][2] = i;
                term[doc][seq][3] = 1;
                term[doc][seq][5] = 0;
                term[doc][seq][6] = 0;
                seq++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')){
            term[doc][seq-1][3]++;
            term[doc][seq-1][4] = djb2(content, term[doc][seq-1][2], term[doc][seq-1][3]);
        }
        prev = chr;
    }
    term[doc][seq][3] = '\0';
    tf(term[doc]);
    return 0;
}

static void tf(float term[][7]){ 
    unsigned int max = 0;
    for(unsigned int t = 0; t < (MAX_TERMS - 1) && term[t][3] != '\0'; t++) max++;
    for(unsigned int t = 0; t < max; t++){
        for(unsigned int i = 0; i < max; i++)
            if(term[t][4] == term[i][4]) term[t][5]++;
        term[t][6] = term[t][5] / max;
    }
}
