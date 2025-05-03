#ifndef EXPR_H
#define EXPR_H

#include <stdlib.h>

#define NUMBER_OF_EXPR 5
#define NUMBER_OF_REG 8

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

typedef enum {
    REG_UU,
    REG_RBX,
    REG_R10,
    REG_R11,
    REG_R12,
    REG_R13,
    REG_R14,
    REG_R15,
} reg_t;

struct expr {
    expr_t kind;
    expr* left;
    expr* right;
    union{
        int i;
        float f;
    } value;
    type_t type;
    reg_t reg;
};

extern const char *EXPR_STR_MAP[NUMBER_OF_EXPR];
extern const char* expr_kind_symbol[NUMBER_OF_EXPR];
extern const char* REG_STR_MAP[NUMBER_OF_REG];

expr* expr_create( expr_t kind,
                   expr *left,
                   expr *right );
    
expr* expr_create_int_value( int value );
expr* expr_create_float_value( float value );
#endif