#include "djb2.h"
#include "input.h"

unsigned int djb2(unsigned int position, unsigned short length){
    unsigned int hash = 5381;
    for(unsigned int i = position; i < (position + length); i++) hash = ((hash << 5) + hash) + input[i];
    return hash;
}
