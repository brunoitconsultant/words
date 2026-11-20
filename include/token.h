#define MAX_TOKENS 200000000

enum token_action {
    TOKENIZE = '3'
};
extern unsigned int token[MAX_TOKENS][4];
int tokenize(void);
