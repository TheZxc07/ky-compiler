#include "ast_primitives.h"

type* type_create( type_t kind, 
                   type* subtype,
                   param_list* params)
{
    type* t = malloc(sizeof(*t));
    t->kind = kind;
    t->subtype = subtype;
    t->params = params;
    return t;
    
}


param_list* param_list_create( char* name,
                               type* type,
                               param_list* next )
{
    param_list* p = malloc(sizeof(*p));
    p->name = name;
    p->type = type;
    p->next = next;
    return p;
}