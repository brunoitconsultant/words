#include "djb2.h"
#include "token.h"

unsigned int token[MAX_TOKENS][5] = { { '\0' } };

int tokenize(unsigned char document[MAX_CHARS], unsigned short docid){
    unsigned char chr, prev = '\0';
    unsigned int id = 0;
    for(unsigned int i = 0; ((chr = document[i]) != '\0'); i++){
        if(
            ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
            && ((prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z')))
        ){
            if(id < (MAX_TOKENS - 1)){
                token[id][0] = id;
                token[id][1] = i;
                token[id][2] = 1;
                token[id][4] = docid;
                id++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')){
            token[id-1][2]++;
            token[id-1][3] = djb2(document, token[id-1][1], token[id-1][2]);
        }
        prev = chr;
    }
    token[id][2] = '\0';
    return 0;
}
