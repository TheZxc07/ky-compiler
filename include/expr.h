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

typedef enum {
    TYPE_VOID,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_ERROR,
} type_t;


struct expr {
    expr_t kind;
    expr* left;
    expr* right;
    union{
        int i;
        float f;
    } value;
    type_t type;
};

extern const char *EXPR_STR_MAP[NUMBER_OF_EXPR];
extern const char* expr_kind_symbol[NUMBER_OF_EXPR];

expr* expr_create( expr_t kind,
                   expr *left,
                   expr *right );
    
expr* expr_create_int_value( int value );
expr* expr_create_float_value( float value );
#endif