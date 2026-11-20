#include "lexic.h"
#include "token.h"

unsigned int lexic[MAX_WORDS][2] = { { '\0' } };

int lexicalize(){
    for(unsigned int i = 0; i < MAX_WORDS; i++){ lexic[i][0] = 0; lexic[i][1] = 0; }
    for(unsigned int i = 0; i < (MAX_TOKENS - 1) && token[i][2] != '\0'; i++){
        unsigned int id = (token[i][3] % MAX_WORDS);
        while(lexic[id][1] > 0 && lexic[id][0] != token[i][3]){ id++; }
        lexic[id][0] = token[i][3];
        lexic[id][1]++;
    }
    return 0;
}
