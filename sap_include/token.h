#ifndef TOKEN_H
#define TOKEN_H

#define NUMBER_OF_TOKENS 13

typedef enum {
    TOKEN_EOF=0,
    TOKEN_UNTIL,
    TOKEN_ADD,
    TOKEN_SUBTRACT,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_IDENT,
    TOKEN_NUMBER,
    TOKEN_ERROR,
    TOKEN_INT,
    TOKEN_FLOAT,
} token_t;

extern const char *TOKEN_STR_MAP[NUMBER_OF_TOKENS];

#endif