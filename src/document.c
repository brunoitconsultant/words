#include <stdio.h>
#include "djb2.h"
#include "document.h"

unsigned char document[MAX_DOCS][MAX_CHARS] = { { '\0' } };

int itoa(unsigned int in, char out[]){ 
    out[0] = '3';
    out[1] = '2';
    out[2] = '1';
    out[3] = '\n';
}

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
   
    unsigned int hash_i = djb2(document[id], 0, i-1);    
    char hash_a[20]; itoa(hash_i, hash_a);
    char hash_a_1 = hash_a[0];

    clearerr(stdin);
    return i;
}
