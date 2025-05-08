%{
#include "token.h"
%}
DIGIT [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n) /* skip whitespace */
\+ { return TOKEN_PLUS; }
\- { return TOKEN_MINUS; }
\* { return TOKEN_MUL; }
\/ { return TOKEN_DIV; }
\( { return TOKEN_LPAREN; }
\) { return TOKEN_RPAREN; }
\; { return TOKEN_SEMI; }
\= { return TOKEN_ASSIGN; }
\, { return TOKEN_COMMA; }
void { return TOKEN_VOID_TYPE; }
int { return TOKEN_INT_TYPE; }
string { return TOKEN_STRING_TYPE; }
while { return TOKEN_WHILE; }
for { return TOKEN_FOR; }
if { return TOKEN_IF; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.name = strdup(yytext); return TOKEN_IDENT; }
{DIGIT}+\.{DIGIT}+ {return TOKEN_FLOAT; }
{DIGIT}+ { return TOKEN_INT; }
. { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }
