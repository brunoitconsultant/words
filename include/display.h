#include "config.h"
#include "term.h"

void display_menu();
void display_library(unsigned char library[][MAX_CHARS]);
void display_stats(unsigned char library[][MAX_CHARS]);
void display_tfidf(float term[][MAX_TERMS][TERM_ATT], unsigned char document[][MAX_CHARS]);
