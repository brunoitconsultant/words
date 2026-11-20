#define MAX_WORDS 1000000

enum lexic_action {
    LEXICALIZE = '4'
};
extern unsigned int lexic[MAX_WORDS][2];
int lexicalize(void);
