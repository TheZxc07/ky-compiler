#include "ast_primitives.h"

stmt* stmt_create( stmt_t kind,
                   decl* decl,
                   expr* init_expr,
                   expr* cond_expr,
                   expr* next_expr,
                   stmt* body,
                   stmt* else_body,
                   stmt* next )
{
    stmt* s = malloc(sizeof(*s));
    s->kind = kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = cond_expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;
    return s;
}
