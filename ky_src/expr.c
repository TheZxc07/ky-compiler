#include "ast_primitives.h"

const char *EXPR_STR_MAP[NUMBER_OF_EXPR] = {
    "EXPR_ADD     ",
    "EXPR_SUBTRACT",
    "EXPR_DIVIDE  ",
    "EXPR_MULTIPLY",
    "EXPR_VALUE   ",
};

const char *REG_STR_MAP[NUMBER_OF_REG] = {
    "REG_UU",
    "%rbx",
    "%r10",
    "%r11",
    "%r12",
    "%r13",
    "%r14",
    "%r15",
};


const char* expr_kind_symbol[NUMBER_OF_EXPR] = {
    "+", "-", "/", "*", "INT"
};

expr* expr_create( expr_t kind,
                   expr *left,
                   expr *right )
{
    expr* e = malloc(sizeof(*e));
    e->reg = REG_UU;
    e->kind = kind;
    e->type = TYPE_VOID;
    e->value.i = 0;
    e->left = left;
    e->right = right;
    return e;
}

expr* expr_create_int_value( int value )
{
    expr* e = expr_create(EXPR_VALUE,0,0);
    e->type = TYPE_INTEGER;
    e->value.i = value;
    //printf("%d", e->value.i);
    return e;
}

expr* expr_create_float_value( float value )
{
    expr* e = expr_create(EXPR_VALUE,0,0);
    e->type = TYPE_CHARACTER;
    e->value.f = value;
    return e;
}

