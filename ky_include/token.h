/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
#include "ast_primitives.h"
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_INT = 258,               /* TOKEN_INT  */
    TOKEN_PLUS = 259,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 260,             /* TOKEN_MINUS  */
    TOKEN_MUL = 261,               /* TOKEN_MUL  */
    TOKEN_DIV = 262,               /* TOKEN_DIV  */
    TOKEN_MODULO = 263,            /* TOKEN_MODULO  */
    TOKEN_LPAREN = 264,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 265,            /* TOKEN_RPAREN  */
    TOKEN_NOT = 266,               /* TOKEN_NOT  */
    TOKEN_BW_NOT = 267,            /* TOKEN_BW_NOT  */
    TOKEN_SEMI = 268,              /* TOKEN_SEMI  */
    TOKEN_ERROR = 269,             /* TOKEN_ERROR  */
    TOKEN_WHILE = 270,             /* TOKEN_WHILE  */
    TOKEN_FOR = 271,               /* TOKEN_FOR  */
    TOKEN_IF = 272,                /* TOKEN_IF  */
    TOKEN_ELSE = 273,              /* TOKEN_ELSE  */
    TOKEN_IDENT = 274,             /* TOKEN_IDENT  */
    TOKEN_FLOAT = 275,             /* TOKEN_FLOAT  */
    TOKEN_ASSIGN = 276,            /* TOKEN_ASSIGN  */
    TOKEN_RETURN = 277,            /* TOKEN_RETURN  */
    TOKEN_RBRACE = 278,            /* TOKEN_RBRACE  */
    TOKEN_LBRACE = 279,            /* TOKEN_LBRACE  */
    TOKEN_COMMA = 280,             /* TOKEN_COMMA  */
    TOKEN_INT_TYPE = 281,          /* TOKEN_INT_TYPE  */
    TOKEN_VOID_TYPE = 282,         /* TOKEN_VOID_TYPE  */
    TOKEN_CHAR_TYPE = 283,         /* TOKEN_CHAR_TYPE  */
    TOKEN_STRING_TYPE = 284        /* TOKEN_STRING_TYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser.bison"

    decl* decl;
    stmt* stmt;
    expr* expr;
    type* type;
    param_list* param_list;
    char* name;
    int int_literal;

#line 103 "token.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
