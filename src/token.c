#include "djb2.h"
#include "token.h"

unsigned int token[MAX_DOCS][MAX_TOKENS][5] = { { { '\0' } } };

int tokenize(unsigned char content[MAX_CHARS], unsigned short document){
    unsigned char chr, prev = '\0';
    unsigned int seq = 0;
    for(unsigned int i = 0; ((chr = content[i]) != '\0'); i++){
        if(
            ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
            && ((prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z')))
        ){
            if(seq < (MAX_TOKENS - 1)){
                token[document][seq][0] = seq;
                token[document][seq][1] = document;
                token[document][seq][2] = i;
                token[document][seq][3] = 1;
                seq++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')){
            token[document][seq-1][3]++;
            token[document][seq-1][4] = djb2(content, token[document][seq-1][2], token[document][seq-1][3]);
        }
        prev = chr;
    }
    token[document][seq][3] = '\0';
    return 0;
}
