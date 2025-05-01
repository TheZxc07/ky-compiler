#ifndef EXPR_H
#define EXPR_H

typedef struct expr expr;

struct expr {
    expr_t kind;
    expr* left;
    expr* right;
    int value;
};
    
typedef enum {
    EXPR_ADD,
    EXPR_SUBTRACT,
    EXPR_DIVIDE,
    EXPR_MULTIPLY,
    EXPR_VALUE
} expr_t;

expr* expr_create( expr_t kind,
                   expr *left,
                   expr *right );
    
expr* expr_create_value( int value );
#endif