%{
#include <stdio.h>
#include "ast_primitives.h"
decl* parser_result = 0;
%}
%token <int_literal> TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_MODULO
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_NOT
%token TOKEN_BW_NOT
%token TOKEN_SEMI
%token TOKEN_ERROR
%token TOKEN_WHILE
%token TOKEN_FOR
%token TOKEN_IF
%token TOKEN_ELSE
%token <name> TOKEN_IDENT
%token TOKEN_FLOAT
%token TOKEN_ASSIGN
%token TOKEN_RETURN
%token TOKEN_RBRACE
%token TOKEN_LBRACE
%token TOKEN_COMMA
%token TOKEN_INT_TYPE
%token TOKEN_VOID_TYPE
%token TOKEN_CHAR_TYPE
%token TOKEN_STRING_TYPE

%union {
    decl* decl;
    stmt* stmt;
    expr* expr;
    type* type;
    param_list* param_list;
    char* name;
    int int_literal;
};

%type <stmt> stmt_list stmt
%type <decl> program decl_list decl 
%type <name> name
%type <type> type
%type <param_list> param_list param_list_no_name param param_no_name param_list_no_name_nonempty param_list_nonempty
%type <expr> expr factor0 factor1 factor2

%%
program : decl_list
          { parser_result = $1; }
        ;

decl_list : decl decl_list
            { $$ = $1; $1->next = $2; }
          | /* epsilon */
            { $$ = 0; }
          ;

decl : type name TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE /* func decl and init */
       { $$ = decl_create($2,$1,0,0,0); $1->params = $4; }
     | type name TOKEN_LPAREN TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE /* func decl and init no params */
       { $$ = decl_create($2,$1,0,$6,0); }
     | type name TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMI /* func prototype */
       { $$ = decl_create($2,$1,0,0,0); $1->params = $4; }
     | type name TOKEN_LPAREN param_list_no_name TOKEN_RPAREN TOKEN_SEMI /* func prototype no ident */
       { $$ = decl_create($2,$1,0,0,0); $1->params = $4; }
     | type name TOKEN_LPAREN TOKEN_RPAREN TOKEN_SEMI /* func prototype no params */
       { $$ = decl_create($2,$1,0,0,0); }
     | type name TOKEN_SEMI /* var decl */
       { $$ = decl_create($2,$1,0,0,0); }
     | type name TOKEN_ASSIGN expr TOKEN_SEMI /* var decl and init */   
       { $$ = decl_create($2,$1,$4,0,0); }
     ; 

stmt_list : stmt stmt_list { $$ = $1; $1->next = $2; }
          | /* epsilon */ { $$ = 0; }
          ;
          
stmt : TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE 
       { $$ = stmt_create(STMT_IF_ELSE,0,0,$3,0,$6,0,0); } /* if with multiple stmts */
     | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE stmt_list TOKEN_RBRACE
       { $$ = stmt_create(STMT_IF_ELSE,0,0,$3,0,$6,$10,0); } /* if-else with multiple stmts */
     | TOKEN_FOR TOKEN_LPAREN TOKEN_SEMI TOKEN_SEMI TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE 
       { $$ = stmt_create(STMT_FOR,0,0,0,0,$7,0,0); }
     | TOKEN_WHILE TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE
       { $$ = stmt_create(STMT_IF_ELSE,0,0,$3,0,$6,0,0); }
     | decl { $$ = stmt_create(STMT_DECL,$1,0,0,0,0,0,0); } 
     | TOKEN_RETURN TOKEN_SEMI { $$ = stmt_create(STMT_RETURN,0,0,0,0,0,0,0); }
     ;

param_list_no_name : param_list_no_name_nonempty { $$ = $1; }
                   ;
    
param_list_no_name_nonempty : param_no_name { $$ = $1; }
                            | param_no_name TOKEN_COMMA param_list_no_name_nonempty { $1->next = $3; $$ = $1; }
                            ;

param_no_name : type { $$ = param_list_create(0, $1, 0); }
              ;

param_list : param_list_nonempty { $$ = $1; }
           ;

param_list_nonempty : param { $$ = $1; }
                    | param TOKEN_COMMA param_list_nonempty { $1->next = $3; $$ = $1; }
                    ;

param : type name { $$ = param_list_create($2, $1, 0); }
      ;

name : TOKEN_IDENT { $$ = $1; }

type : TOKEN_VOID_TYPE { $$ = type_create(TYPE_VOID, 0, 0); }
     | TOKEN_INT_TYPE { $$ = type_create(TYPE_INTEGER, 0, 0); }
     | TOKEN_STRING_TYPE { $$ = type_create(TYPE_STRING, 0, 0); }
     | TOKEN_CHAR_TYPE { $$ = type_create(TYPE_CHARACTER, 0, 0); }
     ;


expr : expr TOKEN_PLUS factor2
     | expr TOKEN_MINUS factor2
     | factor2 { $$ = $1; }
     ;

factor0 : TOKEN_LPAREN expr TOKEN_RPAREN
        | TOKEN_INT { $$ = expr_create_value($1); }
        | name
        ;

factor1 : TOKEN_MINUS factor1
        | TOKEN_PLUS factor1
        | TOKEN_NOT factor1
        | TOKEN_BW_NOT factor1
        | factor0 { $$ = $1; }
        ;

factor2 : factor2 TOKEN_MUL factor1
        | factor2 TOKEN_DIV factor1
        | factor2 TOKEN_MODULO factor1
        | factor1 { $$ = $1; }

%%
int yyerror( char *s ) {
printf("parse error: %s\n",s);
return 1;
}