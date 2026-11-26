#include "djb2.h"
#include "token.h"

unsigned int token[MAX_DOCS][MAX_TOKENS][5] = { { { '\0' } } };

int tokenize(unsigned char content[MAX_CHARS], unsigned short doc){
    unsigned char chr, prev = '\0';
    unsigned int seq = 0;
    for(unsigned int i = 0; ((chr = content[i]) != '\0'); i++){
        if(
            ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
            && ((prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z')))
        ){
            if(seq < (MAX_TOKENS - 1)){
                token[doc][seq][0] = seq;
                token[doc][seq][1] = doc;
                token[doc][seq][2] = i;
                token[doc][seq][3] = 1;
                seq++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')){
            token[doc][seq-1][3]++;
            token[doc][seq-1][4] = djb2(content, token[doc][seq-1][2], token[doc][seq-1][3]);
        }
        prev = chr;
    }
    token[doc][seq][3] = '\0';
    return 0;
}
