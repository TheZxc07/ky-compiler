%{
#include "token.h"
%}
DIGIT [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n) /* skip whitespace */
\+ { return TOKEN_ADD; }
\- { return TOKEN_SUBTRACT; }
\* { return TOKEN_MULTIPLY; }
\/ { return TOKEN_DIVIDE; }
\( { return TOKEN_LPAREN; }
\) { return TOKEN_RPAREN; }
until { return TOKEN_UNTIL; }
{LETTER}+ { return TOKEN_IDENT; }
{DIGIT}+ { return TOKEN_INT; }
. { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }
