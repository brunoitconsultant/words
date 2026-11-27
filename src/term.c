#include "djb2.h"
#include "term.h"

unsigned int term[MAX_DOCS][MAX_TERMS][6] = { { { '\0' } } };
static void count(unsigned int term[][6]);

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
                seq++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')){
            term[doc][seq-1][3]++;
            term[doc][seq-1][4] = djb2(content, term[doc][seq-1][2], term[doc][seq-1][3]);
        }
        prev = chr;
    }
    term[doc][seq][3] = '\0';
    count(term[doc]);
    return 0;
}

static void count(unsigned int term[][6]){  
    for(unsigned int t = 0; t < (MAX_TERMS - 1) && term[t][3] != '\0'; t++){
        unsigned int hash = term[t][4];
        for(unsigned int i = 0; i < (MAX_TERMS - 1) && term[i][3] != '\0'; i++)
            if(hash == term[i][4]) term[t][5]++;
    }
}
