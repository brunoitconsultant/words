#include "djb2.h"
#include "token.h"

unsigned int token[MAX_TOKENS][4] = { { '\0' } };

int tokenize(unsigned char input[MAX_CHARS]){
    unsigned char chr, prev = '\0';
    unsigned int id = 0;
    for(unsigned int i = 0; ((chr = input[i]) != '\0'); i++){
        if(
            ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'))
            && ((prev < '0' || (prev > '9' && prev < 'A') || ((prev > 'Z' && prev < 'a') && prev > 'z')))
        ){
            if(id < (MAX_TOKENS - 1)){
                token[id][0] = id;
                token[id][1] = i;
                token[id][2] = 1;
                id++;
            }else break;
        }else if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9')) token[id-1][2]++;
        else token[id-1][3] = djb2(input, token[id-1][1], token[id-1][2]);
        prev = chr;
    }
    token[id][2] = '\0';
    return 0;
}
