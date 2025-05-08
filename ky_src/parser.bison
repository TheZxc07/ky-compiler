%{
#include <stdio.h>
#include "ast_primitives.h"
decl* parser_result = 0;
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
%token <name> TOKEN_IDENT
%token TOKEN_FLOAT
%token TOKEN_ASSIGN
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
};

%type <decl> program decl_list decl 
%type <stmt> stmt_list stmt
%type <name> name
%type <type> type
%type <param_list> param_list param_list_no_name param param_no_name param_list_no_name_nonempty param_list_nonempty

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
       { $$ = decl_create($2,$1,0,0,0); }
     | type name TOKEN_LPAREN param_list_no_name TOKEN_RPAREN TOKEN_SEMI /* func prototype no ident */
       { $$ = decl_create($2,$1,0,0,0); $1->params = $4; }
     | type name TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMI /* func prototype no params */
       { $$ = decl_create($2,$1,0,0,0); }
     | type name TOKEN_SEMI /* global decl */
       { $$ = decl_create($2,$1,0,0,0); }
     | type name TOKEN_ASSIGN expr TOKEN_SEMI /* global decl and init */   
       { $$ = decl_create($2,$1,0,0,0); }
     ; 

stmt_list : /* epsilon */ { $$ = 0; }
          ;
          
stmt : TOKEN_IF { $$ = 0; }
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