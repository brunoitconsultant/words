#include "lexic.h"

unsigned int lexic[MAX_DOCS][MAX_WORDS][2] = { { { '\0' } } };
static void clear(unsigned short doc);

int lexicalize(unsigned int token[][MAX_TOKENS][5], unsigned short doc){
    clear(doc);
    for(unsigned int i = 0; i < (MAX_TOKENS - 1) && token[doc][i][3] != '\0'; i++){
        unsigned int id = (token[doc][i][4] % MAX_WORDS);
        while(lexic[doc][id][1] > 0 && lexic[doc][id][0] != token[doc][i][4]){ id++; }
        lexic[doc][id][0] = token[doc][i][4];
        lexic[doc][id][1]++;
    }
    return 0;
}

static void clear(unsigned short doc){
    for(unsigned int i = 0; i < MAX_WORDS; i++){ lexic[doc][i][0] = '\0'; lexic[doc][i][1] = '\0'; }
}
