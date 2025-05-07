#include "ast_primitives.h"

decl* decl_create( char* name,
                   type* type,
                   expr* value,
                   stmt* code,
                   decl* next )
{
    decl* d = malloc(sizeof(*d));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}
    