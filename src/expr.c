#include "expr.h"

expr* expr_create( expr_t kind,
                   expr *left,
                   expr *right )
{
    expr* e = malloc(sizeof(*e));
    e->kind = kind;
    e->value = 0;
    e->left = left;
    e->right = right;
    return e;
}

expr* expr_create_value( int value )
{
    expr* e = expr_create(EXPR_VALUE,0,0);
    e->value = value;
    return e;
}
