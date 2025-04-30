#include "llg_parser.h"
/*
The Parsers GRAMMAR 
1. prog   → expr
2. expr   → term expr'
3. expr'  → + term expr'
          | - term expr'
          | ε

4. term   → factor term'
5. term'  → * factor term'
          | / factor term'
          | ε

6. factor → int 
          | float
          | ( expr )
*/

token_st* scan_token(llist_t* token_stream){

    token_st* next_token = (token_st*)malloc(sizeof(token_st));
    pop_front(token_stream, next_token);

    return next_token;
}

void putback_token(token_st* token, llist_t* token_stream){
    push_front(token_stream, token);
}

int expect_token(token_t token, llist_t* token_stream){
    token_st* next_token;

    next_token = scan_token(token_stream);
    if (next_token->token_type == token){
        free(next_token);
        return 1;
    } else {
        putback_token(next_token, token_stream);
        return 0;
    }
}

int parse_prog(llist_t* token_stream){
    return parse_expr(token_stream) && expect_token(TOKEN_EOF, token_stream);
}

int parse_expr(llist_t* token_stream){
    return parse_term(token_stream) && parse_expr_prime(token_stream);
}

int parse_expr_prime(llist_t* token_stream){
    token_st* t = scan_token(token_stream);
    if (t->token_type == TOKEN_ADD) {
        //printf("%s\n", t->s_token);
        return parse_term(token_stream) && parse_expr_prime(token_stream);
    } else if (t->token_type == TOKEN_SUBTRACT) {
        return parse_term(token_stream) && parse_expr_prime(token_stream);
    } else {
        putback_token(t, token_stream);
        return 1;
    }
}

int parse_term(llist_t* token_stream){
    //printf("Visted\n"); 
    return parse_factor(token_stream) && parse_term_prime(token_stream);
}

int parse_term_prime(llist_t* token_stream){
    token_st* t = scan_token(token_stream);
    if (t->token_type == TOKEN_MULTIPLY){
        return parse_factor(token_stream) && parse_term_prime(token_stream);
    } else if (t->token_type == TOKEN_DIVIDE){
        return parse_factor(token_stream) && parse_term_prime(token_stream);
    } else {
        //printf("%s\n", t->s_token);
        putback_token(t, token_stream);
        return 1;
    }

}

int parse_factor(llist_t* token_stream){
    token_st* t = scan_token(token_stream);
    //printf("%s\n", t->s_token);
    if (t->token_type == TOKEN_LPAREN){
        return parse_expr(token_stream) && expect_token(TOKEN_RPAREN, token_stream);
    } else if (t->token_type == TOKEN_INT){
        //printf("%s\n", t->s_token);
        return 1;
    } else if (t->token_type == TOKEN_FLOAT){
        return 1;
    } else {
        return 0;
    }

}