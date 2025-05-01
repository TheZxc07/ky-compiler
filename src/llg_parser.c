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

expr* parse_prog(llist_t* token_stream){
    expr* AST = parse_expr(token_stream);
    if (!expect_token(TOKEN_EOF, token_stream)){
        return NULL;
    } else {
        return AST;
    }
}

expr* parse_expr(llist_t* token_stream){

    expr* term = parse_term(token_stream);
    expr* expr_prime = parse_expr_prime(token_stream);

    if (expr_prime == NULL){
        return term;
    } else {
        expr* t_ptr = expr_prime;
        while (t_ptr->left != NULL){
            t_ptr = t_ptr->left;
        }
        t_ptr->left = term;
        return expr_prime;
    }
    //return parse_term(token_stream) && parse_expr_prime(token_stream);
}

expr* parse_expr_prime(llist_t* token_stream){
    token_st* t = scan_token(token_stream);
    if (t->token_type == TOKEN_ADD) {
        //printf("%s\n", t->s_token);
        expr* term = parse_term(token_stream);
        expr* expr_prime = expr_create(EXPR_ADD, NULL, NULL);
        expr* higher_expr_prime = parse_expr_prime(token_stream);

        expr_prime-> right = term;
        if (higher_expr_prime == NULL){
            return expr_prime;
        } else {
            expr* t_ptr = higher_expr_prime;
            while(t_ptr->left != NULL){
                t_ptr = t_ptr->left;
            }
            t_ptr->left = expr_prime;
            return higher_expr_prime;
        }
    } else if (t->token_type == TOKEN_SUBTRACT) {
        expr* term = parse_term(token_stream);
        expr* expr_prime = expr_create(EXPR_SUBTRACT, NULL, NULL);
        expr* higher_expr_prime = parse_expr_prime(token_stream);

        expr_prime-> right = term;
        if (higher_expr_prime == NULL){
            return expr_prime;
        } else {
            expr* t_ptr = higher_expr_prime;
            while(t_ptr->left != NULL){
                t_ptr = t_ptr->left;
            }
            t_ptr->left = expr_prime;
            return higher_expr_prime;
        }
    } else {
        putback_token(t, token_stream);
        return NULL;
    }
}

expr* parse_term(llist_t* token_stream){
    //printf("Visted\n"); 
    expr* factor = parse_factor(token_stream);
    expr* term_prime = parse_term_prime(token_stream);

    if (term_prime == NULL){
        return factor;
    } else {
        expr* t_ptr = term_prime;
        while (t_ptr->left != NULL){
            t_ptr = t_ptr->left;
        }
        t_ptr->left = factor;
        return term_prime;
    }
}

expr* parse_term_prime(llist_t* token_stream){
    token_st* t = scan_token(token_stream);
    if (t->token_type == TOKEN_MULTIPLY){
        expr* factor = parse_factor(token_stream);
        expr* term_prime = expr_create(EXPR_MULTIPLY, NULL, NULL);
        expr* higher_term_prime = parse_term_prime(token_stream);

        term_prime->right = factor;
        if (higher_term_prime == NULL){
            return term_prime;
        } else {
            expr* t_ptr = higher_term_prime;
            while (t_ptr->left != NULL){
                t_ptr = t_ptr->left;
            }
            t_ptr->left = term_prime;
            return higher_term_prime;
        }
        //return parse_factor(token_stream) && parse_term_prime(token_stream);
    } else if (t->token_type == TOKEN_DIVIDE){
        expr* factor = parse_factor(token_stream);
        expr* term_prime = expr_create(EXPR_DIVIDE, NULL, NULL);
        expr* higher_term_prime = parse_term_prime(token_stream);
        
        term_prime->right = factor;
        if (higher_term_prime == NULL){
            return term_prime;
        } else {
            expr* t_ptr = higher_term_prime;
            while (t_ptr->left != NULL){
                t_ptr = t_ptr->left;
            }
            t_ptr->left = term_prime;
            return higher_term_prime;
        }
    } else {
        //printf("%s\n", t->s_token);
        putback_token(t, token_stream);
        return NULL;
    }

}

expr* parse_factor(llist_t* token_stream){
    token_st* t = scan_token(token_stream);
    //printf("%s\n", t->s_token);
    if (t->token_type == TOKEN_LPAREN){
        expr* expr = parse_expr(token_stream);
        if (!expect_token(TOKEN_RPAREN, token_stream)){
            return NULL;
        } else {
            return expr;
        }
    } else if (t->token_type == TOKEN_INT){
        //printf("%s\n", t->s_token);
        return expr_create_value(atoi(t->s_token));
        //return 1;
    } else if (t->token_type == TOKEN_FLOAT){
        return expr_create_value(0);
    } else {
        return NULL;
    }
}

void print_ast(expr* t){
    __print_ast(t, 0);
}

void __print_ast(expr* t, int level) {
    if (t == NULL) return;

    __print_ast(t->right, level + 1);

    for (int i = 0; i < level; i++) printf("    ");

    if (t->kind == EXPR_VALUE) {
        printf("%d\n", t->value);
    } else {
        printf("%s\n", expr_kind_symbol[t->kind]);
    }

    __print_ast(t->left, level + 1);
}