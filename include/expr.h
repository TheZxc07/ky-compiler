#ifndef EXPR_H
#define EXPR_H

#include <stdlib.h>

#define NUMBER_OF_EXPR 5

typedef struct expr expr;

typedef enum {
    EXPR_ADD,
    EXPR_SUBTRACT,
    EXPR_DIVIDE,
    EXPR_MULTIPLY,
    EXPR_VALUE
} expr_t;


struct expr {
    expr_t kind;
    expr* left;
    expr* right;
    int value;
};

extern const char *EXPR_STR_MAP[NUMBER_OF_EXPR];
extern const char* expr_kind_symbol[NUMBER_OF_EXPR];

expr* expr_create( expr_t kind,
                   expr *left,
                   expr *right );
    
expr* expr_create_value( int value );
#endif