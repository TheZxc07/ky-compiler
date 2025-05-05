%{
#include <stdio.h>
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
%%
program : expr TOKEN_SEMI;
expr : expr TOKEN_PLUS term
| expr TOKEN_MINUS term
| term
;
term : term TOKEN_MUL factor
| term TOKEN_DIV factor
| factor
;
factor: TOKEN_MINUS factor
| TOKEN_LPAREN expr TOKEN_RPAREN
| TOKEN_INT
;
%%
int yyerror( char *s ) {
printf("parse error: %s\n",s);
return 1;
}