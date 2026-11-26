#include "djb2.h"
#include "token.h"

unsigned int token[MAX_TOKENS][5] = { { '\0' } };

int tokenize(unsigned char document[MAX_CHARS], unsigned short id){
    unsigned char chr, prev = '\0';
    unsigned int seq = 0;
    for(unsigned int i = 0; ((chr = document[i]) != '\0'); i++){
        if(
            ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
            && ((prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z')))
        ){
            if(seq < (MAX_TOKENS - 1)){
                token[seq][0] = seq;
                token[seq][1] = id;
                token[seq][2] = i;
                token[seq][3] = 1;
                seq++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')){
            token[seq-1][3]++;
            token[seq-1][4] = djb2(document, token[seq-1][2], token[seq-1][3]);
        }
        prev = chr;
    }
    token[seq][3] = '\0';
    return 0;
}
