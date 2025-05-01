#ifndef LLG_PARSER_H
#define LLG_PARSER_H

#include "token.h"
#include "llist.h"
#include "expr.h"
#include <stdlib.h>

token_st* scan_token(llist_t* token_stream);
void putback_token(token_st* token, llist_t* token_stream);
int expect_token(token_t token, llist_t* token_stream);

expr* parse_prog(llist_t* token_stream);
expr* parse_expr(llist_t* token_stream);
expr* parse_expr_prime(llist_t* token_stream);
expr* parse_term(llist_t* token_stream);
expr* parse_term_prime(llist_t* token_stream);
expr* parse_factor(llist_t* token_stream);

void print_ast(expr* root);
void __print_ast(expr* t, int level);

#endif