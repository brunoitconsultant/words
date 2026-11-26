#include <stdio.h>
#include "document.h"

unsigned char document[MAX_DOCS][MAX_CHARS] = { { '\0' } };

int upload(char method){
    char c;
    unsigned short id;
    unsigned int i = 0;
    
    if      (method == DOC_1)   id = DOC_1 - '1'; 
    else if (method == DOC_2)   id = DOC_2 - '1'; 
    else if (method == DOC_3)   id = DOC_3 - '1';
    else                        return i;

    while((c = getchar()) != EOF) if((i + 1) < MAX_CHARS) document[id][i++] = c;
    
    document[id][i] = '\0';
    clearerr(stdin);
    return i;
}
