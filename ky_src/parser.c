/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.bison"

#include <stdio.h>
#include "ast_primitives.h"
decl* parser_result = 0;

#line 77 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "token.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_PLUS = 4,                 /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 5,                /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MUL = 6,                  /* TOKEN_MUL  */
  YYSYMBOL_TOKEN_DIV = 7,                  /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MODULO = 8,               /* TOKEN_MODULO  */
  YYSYMBOL_TOKEN_LPAREN = 9,               /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 10,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_NOT = 11,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_BW_NOT = 12,              /* TOKEN_BW_NOT  */
  YYSYMBOL_TOKEN_SEMI = 13,                /* TOKEN_SEMI  */
  YYSYMBOL_TOKEN_ERROR = 14,               /* TOKEN_ERROR  */
  YYSYMBOL_TOKEN_WHILE = 15,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_FOR = 16,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_IF = 17,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 18,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_IDENT = 19,               /* TOKEN_IDENT  */
  YYSYMBOL_TOKEN_FLOAT = 20,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_ASSIGN = 21,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_RETURN = 22,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_RBRACE = 23,              /* TOKEN_RBRACE  */
  YYSYMBOL_TOKEN_LBRACE = 24,              /* TOKEN_LBRACE  */
  YYSYMBOL_TOKEN_COMMA = 25,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_INT_TYPE = 26,            /* TOKEN_INT_TYPE  */
  YYSYMBOL_TOKEN_VOID_TYPE = 27,           /* TOKEN_VOID_TYPE  */
  YYSYMBOL_TOKEN_CHAR_TYPE = 28,           /* TOKEN_CHAR_TYPE  */
  YYSYMBOL_TOKEN_STRING_TYPE = 29,         /* TOKEN_STRING_TYPE  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_program = 31,                   /* program  */
  YYSYMBOL_decl_list = 32,                 /* decl_list  */
  YYSYMBOL_decl = 33,                      /* decl  */
  YYSYMBOL_stmt_list = 34,                 /* stmt_list  */
  YYSYMBOL_stmt = 35,                      /* stmt  */
  YYSYMBOL_param_list_no_name = 36,        /* param_list_no_name  */
  YYSYMBOL_param_list_no_name_nonempty = 37, /* param_list_no_name_nonempty  */
  YYSYMBOL_param_no_name = 38,             /* param_no_name  */
  YYSYMBOL_param_list = 39,                /* param_list  */
  YYSYMBOL_param_list_nonempty = 40,       /* param_list_nonempty  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_name = 42,                      /* name  */
  YYSYMBOL_type = 43,                      /* type  */
  YYSYMBOL_expr = 44,                      /* expr  */
  YYSYMBOL_factor0 = 45,                   /* factor0  */
  YYSYMBOL_factor1 = 46,                   /* factor1  */
  YYSYMBOL_factor2 = 47                    /* factor2  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    56,    59,    62,    64,    66,    68,    70,
      72,    74,    78,    79,    82,    84,    86,    88,    90,    91,
      94,    97,    98,   101,   104,   107,   108,   111,   114,   116,
     117,   118,   119,   123,   124,   125,   128,   129,   130,   133,
     134,   135,   136,   137,   140,   141,   142,   143
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MUL", "TOKEN_DIV", "TOKEN_MODULO",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_NOT", "TOKEN_BW_NOT",
  "TOKEN_SEMI", "TOKEN_ERROR", "TOKEN_WHILE", "TOKEN_FOR", "TOKEN_IF",
  "TOKEN_ELSE", "TOKEN_IDENT", "TOKEN_FLOAT", "TOKEN_ASSIGN",
  "TOKEN_RETURN", "TOKEN_RBRACE", "TOKEN_LBRACE", "TOKEN_COMMA",
  "TOKEN_INT_TYPE", "TOKEN_VOID_TYPE", "TOKEN_CHAR_TYPE",
  "TOKEN_STRING_TYPE", "$accept", "program", "decl_list", "decl",
  "stmt_list", "stmt", "param_list_no_name", "param_list_no_name_nonempty",
  "param_no_name", "param_list", "param_list_nonempty", "param", "name",
  "type", "expr", "factor0", "factor1", "factor2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      52,   -58,   -58,   -58,   -58,     6,   -58,    52,   -11,   -58,
     -58,   -58,    -4,    -7,   -58,    41,    -1,     8,   -58,     1,
      18,   -58,    26,   -11,   -58,    41,    41,    41,    41,    41,
     -58,    20,   -58,   -58,    32,   -58,    39,    46,    52,     3,
      52,   -58,   -58,   -58,    38,   -58,   -58,    41,    41,   -58,
      41,    41,    41,    64,    73,    74,    61,   -58,    53,    39,
     -58,   -58,   -58,   -58,    39,   -58,   -11,   -58,    32,    32,
     -58,   -58,   -58,    41,    71,    41,   -58,   -58,   -58,    62,
      65,    75,    67,   -58,    63,    76,    66,    39,    68,    39,
      70,    39,    72,   -58,    77,    78,   -58,    79,    39,    81,
     -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    30,    29,    32,    31,     0,     2,     4,     0,     1,
       3,    28,     0,     0,    10,     0,     0,     0,    20,    21,
       0,    24,    25,    23,    37,     0,     0,     0,     0,     0,
      38,     0,    43,    47,    35,     9,    13,     0,     0,     0,
       0,    27,    40,    39,     0,    41,    42,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,    18,     0,    13,
       8,    22,    23,     7,    13,    26,     0,    36,    33,    34,
      44,    45,    46,     0,     0,     0,    19,     6,    12,     0,
       0,     0,     0,     5,     0,     0,     0,    13,     0,    13,
       0,    13,     0,    17,     0,    14,    16,     0,    13,     0,
      15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,    82,    57,   -57,   -58,   -58,    56,   -58,   -58,
      51,   -58,    -8,    -9,   -26,   -58,   -15,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,    57,    58,    59,    17,    18,    19,    20,
      21,    22,    30,     8,    31,    32,    33,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      12,    44,    78,    16,    23,    13,     9,    79,    11,    14,
      42,    43,    35,    45,    46,    41,    63,    15,    37,     1,
       2,     3,     4,    36,    47,    48,    38,    64,    39,    62,
      90,    66,    92,    49,    94,    70,    71,    72,    50,    51,
      52,    99,    47,    48,    24,    25,    26,    80,    67,    82,
      27,    40,    28,    29,    53,    54,    55,     7,    41,    60,
      11,    56,    68,    69,     7,     1,     2,     3,     4,    47,
      48,    47,    48,    73,    76,    84,    77,    86,     1,     2,
       3,     4,    74,    75,    81,    83,    88,    87,    85,    10,
      89,    65,    91,    93,    61,    95,    97,     0,     0,     0,
      96,     0,     0,    98,   100
};

static const yytype_int8 yycheck[] =
{
       8,    27,    59,    10,    13,     9,     0,    64,    19,    13,
      25,    26,    13,    28,    29,    23,    13,    21,    10,    26,
      27,    28,    29,    24,     4,     5,    25,    24,    10,    38,
      87,    40,    89,    13,    91,    50,    51,    52,     6,     7,
       8,    98,     4,     5,     3,     4,     5,    73,    10,    75,
       9,    25,    11,    12,    15,    16,    17,     0,    66,    13,
      19,    22,    47,    48,     7,    26,    27,    28,    29,     4,
       5,     4,     5,     9,    13,    10,    23,    10,    26,    27,
      28,    29,     9,     9,    13,    23,    10,    24,    13,     7,
      24,    40,    24,    23,    38,    23,    18,    -1,    -1,    -1,
      23,    -1,    -1,    24,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    27,    28,    29,    31,    32,    33,    43,     0,
      32,    19,    42,     9,    13,    21,    10,    36,    37,    38,
      39,    40,    41,    43,     3,     4,     5,     9,    11,    12,
      42,    44,    45,    46,    47,    13,    24,    10,    25,    10,
      25,    42,    46,    46,    44,    46,    46,     4,     5,    13,
       6,     7,     8,    15,    16,    17,    22,    33,    34,    35,
      13,    37,    43,    13,    24,    40,    43,    10,    47,    47,
      46,    46,    46,     9,     9,     9,    13,    23,    34,    34,
      44,    13,    44,    23,    10,    13,    10,    24,    10,    24,
      34,    24,    34,    23,    34,    23,    23,    18,    24,    34,
      23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    33,
      33,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      36,    37,    37,    38,    39,    40,    40,    41,    42,    43,
      43,    43,    43,    44,    44,    44,    45,    45,    45,    46,
      46,    46,    46,    46,    47,    47,    47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     8,     7,     6,     6,     5,
       3,     5,     2,     0,     7,    11,     8,     7,     1,     2,
       1,     1,     3,     1,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     1,     2,
       2,     2,     2,     1,     3,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: decl_list  */
#line 53 "parser.bison"
          { parser_result = (yyvsp[0].decl); }
#line 1173 "parser.c"
    break;

  case 3: /* decl_list: decl decl_list  */
#line 57 "parser.bison"
            { (yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next = (yyvsp[0].decl); }
#line 1179 "parser.c"
    break;

  case 4: /* decl_list: %empty  */
#line 59 "parser.bison"
            { (yyval.decl) = 0; }
#line 1185 "parser.c"
    break;

  case 5: /* decl: type name TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE  */
#line 63 "parser.bison"
       { (yyval.decl) = decl_create((yyvsp[-6].name),(yyvsp[-7].type),0,0,0); (yyvsp[-7].type)->params = (yyvsp[-4].param_list); }
#line 1191 "parser.c"
    break;

  case 6: /* decl: type name TOKEN_LPAREN TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE  */
#line 65 "parser.bison"
       { (yyval.decl) = decl_create((yyvsp[-5].name),(yyvsp[-6].type),0,(yyvsp[-1].stmt),0); }
#line 1197 "parser.c"
    break;

  case 7: /* decl: type name TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_SEMI  */
#line 67 "parser.bison"
       { (yyval.decl) = decl_create((yyvsp[-4].name),(yyvsp[-5].type),0,0,0); (yyvsp[-5].type)->params = (yyvsp[-2].param_list); }
#line 1203 "parser.c"
    break;

  case 8: /* decl: type name TOKEN_LPAREN param_list_no_name TOKEN_RPAREN TOKEN_SEMI  */
#line 69 "parser.bison"
       { (yyval.decl) = decl_create((yyvsp[-4].name),(yyvsp[-5].type),0,0,0); (yyvsp[-5].type)->params = (yyvsp[-2].param_list); }
#line 1209 "parser.c"
    break;

  case 9: /* decl: type name TOKEN_LPAREN TOKEN_RPAREN TOKEN_SEMI  */
#line 71 "parser.bison"
       { (yyval.decl) = decl_create((yyvsp[-3].name),(yyvsp[-4].type),0,0,0); }
#line 1215 "parser.c"
    break;

  case 10: /* decl: type name TOKEN_SEMI  */
#line 73 "parser.bison"
       { (yyval.decl) = decl_create((yyvsp[-1].name),(yyvsp[-2].type),0,0,0); }
#line 1221 "parser.c"
    break;

  case 11: /* decl: type name TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 75 "parser.bison"
       { (yyval.decl) = decl_create((yyvsp[-3].name),(yyvsp[-4].type),(yyvsp[-1].expr),0,0); }
#line 1227 "parser.c"
    break;

  case 12: /* stmt_list: stmt stmt_list  */
#line 78 "parser.bison"
                           { (yyval.stmt) = (yyvsp[-1].stmt); (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); }
#line 1233 "parser.c"
    break;

  case 13: /* stmt_list: %empty  */
#line 79 "parser.bison"
                          { (yyval.stmt) = 0; }
#line 1239 "parser.c"
    break;

  case 14: /* stmt: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE  */
#line 83 "parser.bison"
       { (yyval.stmt) = stmt_create(STMT_IF_ELSE,0,0,(yyvsp[-4].expr),0,(yyvsp[-1].stmt),0,0); }
#line 1245 "parser.c"
    break;

  case 15: /* stmt: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE stmt_list TOKEN_RBRACE  */
#line 85 "parser.bison"
       { (yyval.stmt) = stmt_create(STMT_IF_ELSE,0,0,(yyvsp[-8].expr),0,(yyvsp[-5].stmt),(yyvsp[-1].stmt),0); }
#line 1251 "parser.c"
    break;

  case 16: /* stmt: TOKEN_FOR TOKEN_LPAREN TOKEN_SEMI TOKEN_SEMI TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE  */
#line 87 "parser.bison"
       { (yyval.stmt) = stmt_create(STMT_FOR,0,0,0,0,(yyvsp[-1].stmt),0,0); }
#line 1257 "parser.c"
    break;

  case 17: /* stmt: TOKEN_WHILE TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_LBRACE stmt_list TOKEN_RBRACE  */
#line 89 "parser.bison"
       { (yyval.stmt) = stmt_create(STMT_IF_ELSE,0,0,(yyvsp[-4].expr),0,(yyvsp[-1].stmt),0,0); }
#line 1263 "parser.c"
    break;

  case 18: /* stmt: decl  */
#line 90 "parser.bison"
            { (yyval.stmt) = stmt_create(STMT_DECL,(yyvsp[0].decl),0,0,0,0,0,0); }
#line 1269 "parser.c"
    break;

  case 19: /* stmt: TOKEN_RETURN TOKEN_SEMI  */
#line 91 "parser.bison"
                               { (yyval.stmt) = stmt_create(STMT_RETURN,0,0,0,0,0,0,0); }
#line 1275 "parser.c"
    break;

  case 20: /* param_list_no_name: param_list_no_name_nonempty  */
#line 94 "parser.bison"
                                                 { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1281 "parser.c"
    break;

  case 21: /* param_list_no_name_nonempty: param_no_name  */
#line 97 "parser.bison"
                                            { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1287 "parser.c"
    break;

  case 22: /* param_list_no_name_nonempty: param_no_name TOKEN_COMMA param_list_no_name_nonempty  */
#line 98 "parser.bison"
                                                                                    { (yyvsp[-2].param_list)->next = (yyvsp[0].param_list); (yyval.param_list) = (yyvsp[-2].param_list); }
#line 1293 "parser.c"
    break;

  case 23: /* param_no_name: type  */
#line 101 "parser.bison"
                     { (yyval.param_list) = param_list_create(0, (yyvsp[0].type), 0); }
#line 1299 "parser.c"
    break;

  case 24: /* param_list: param_list_nonempty  */
#line 104 "parser.bison"
                                 { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1305 "parser.c"
    break;

  case 25: /* param_list_nonempty: param  */
#line 107 "parser.bison"
                            { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1311 "parser.c"
    break;

  case 26: /* param_list_nonempty: param TOKEN_COMMA param_list_nonempty  */
#line 108 "parser.bison"
                                                            { (yyvsp[-2].param_list)->next = (yyvsp[0].param_list); (yyval.param_list) = (yyvsp[-2].param_list); }
#line 1317 "parser.c"
    break;

  case 27: /* param: type name  */
#line 111 "parser.bison"
                  { (yyval.param_list) = param_list_create((yyvsp[0].name), (yyvsp[-1].type), 0); }
#line 1323 "parser.c"
    break;

  case 28: /* name: TOKEN_IDENT  */
#line 114 "parser.bison"
                   { (yyval.name) = (yyvsp[0].name); }
#line 1329 "parser.c"
    break;

  case 29: /* type: TOKEN_VOID_TYPE  */
#line 116 "parser.bison"
                       { (yyval.type) = type_create(TYPE_VOID, 0, 0); }
#line 1335 "parser.c"
    break;

  case 30: /* type: TOKEN_INT_TYPE  */
#line 117 "parser.bison"
                      { (yyval.type) = type_create(TYPE_INTEGER, 0, 0); }
#line 1341 "parser.c"
    break;

  case 31: /* type: TOKEN_STRING_TYPE  */
#line 118 "parser.bison"
                         { (yyval.type) = type_create(TYPE_STRING, 0, 0); }
#line 1347 "parser.c"
    break;

  case 32: /* type: TOKEN_CHAR_TYPE  */
#line 119 "parser.bison"
                       { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0); }
#line 1353 "parser.c"
    break;

  case 35: /* expr: factor2  */
#line 125 "parser.bison"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 1359 "parser.c"
    break;

  case 37: /* factor0: TOKEN_INT  */
#line 129 "parser.bison"
                    { (yyval.expr) = expr_create_value((yyvsp[0].int_literal)); }
#line 1365 "parser.c"
    break;

  case 43: /* factor1: factor0  */
#line 137 "parser.bison"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 1371 "parser.c"
    break;

  case 47: /* factor2: factor1  */
#line 143 "parser.bison"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 1377 "parser.c"
    break;


#line 1381 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 145 "parser.bison"

int yyerror( char *s ) {
printf("parse error: %s\n",s);
return 1;
}
