%{
#include <stdio.h>
#include "ast_primitives.h"
%}
%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_SEMI
%token TOKEN_ERROR
%token TOKEN_WHILE
%token TOKEN_FOR
%token TOKEN_IF
%token TOKEN_IDENT
%token TOKEN_FLOAT
%token TOKEN_ASSIGN
%token TOKEN_RBRACE
%token TOKEN_LBRACE

%token TOKEN_INT_TYPE
%token TOKEN_VOID_TYPE
%token TOKEN_CHAR_TYPE
%token TOKEN_STRING_TYPE

%union {
    decl* decl;
    stmt* stmt;
    expr* expr;
};

%type <decl> program decl_list decl
%type <stmt> stmt_list stmt

%%
program : decl_list
          { parser_result = $1; }
        ;

decl_list : decl decl_list
            { $$ = $1; $1->next = $2; }
          | /* epsilon */
            { $$ = 0; }
          ;

decl : type name TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMI /* func prototype */
       { $$ = decl_create($2,$1,0,0,0); }
     | type name TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE /* func decl and init */
     | type name TOKEN_SEMI /* global decl */
       { $$ = decl_create($2,$1,0,0,0); }
     | type name TOKEN_ASSIGN expr TOKEN_SEMI /* global decl and init */   
       { $$ = decl_create($2,$1,0,0,0); }
     ; 

param_list : param_list_nonempty { $$ = $1; }
           | /* epsilon */ { $$ = 0; }
           ;

param_list_nonempty : param { $$ = $1; }
                    | param TOKEN_COMMA param_list_nonempty { $1->next = $3; $$ = $1; }
                    ;

type : TOKEN_VOID_TYPE
     | TOKEN_INT_TYPE
     | TOKEN_STRING_TYPE
     | TOKEN_CHAR_TYPE



expr : expr TOKEN_PLUS term
     | expr TOKEN_MINUS term
     | term
     ;
term : term TOKEN_MUL factor
     | term TOKEN_DIV factor
     | factor
     ;
factor : TOKEN_MINUS factor
       | TOKEN_LPAREN expr TOKEN_RPAREN
       | TOKEN_INT
       ;
%%
int yyerror( char *s ) {
printf("parse error: %s\n",s);
return 1;
}