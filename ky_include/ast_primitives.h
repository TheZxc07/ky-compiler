#ifndef AST_PRIMITIVES_H
#define AST_PRIMITIVES_H

#define NUMBER_OF_EXPR 5
#define NUMBER_OF_REG 8

#include <stdlib.h>

typedef struct decl decl;
typedef struct expr expr;
typedef struct stmt stmt;
typedef struct type type;
typedef struct param_list param_list;

typedef enum {
    EXPR_ADD,
    EXPR_SUB,
    EXPR_DIV,
    EXPR_MUL,
    EXPR_VALUE,
    EXPR_BW_OR,
    EXPR_BW_AND,
    EXPR_BW_XOR,
    EXPR_BW_NOT,
    EXPR_OR,
    EXPR_AND,
    EXPR_XOR,
    EXPR_NOT,
    EXPR_NAME,
    EXPR_INT_LITERAL,
    EXPR_FLOAT_LITERAL,
    EXPR_STRING_LITERAL,
} expr_t;

typedef enum {
    STMT_DECL,
    STMT_EXPR,
    STMT_IF_ELSE,
    STMT_FOR,
    STMT_PRINT,
    STMT_RETURN,
    STMT_BLOCK
} stmt_t;

typedef enum {
    TYPE_VOID,
    TYPE_BOOLEAN,
    TYPE_CHARACTER,
    TYPE_INTEGER,
    TYPE_STRING,
    TYPE_ARRAY,
    TYPE_FUNCTION
} type_t;
    
typedef enum {
    REG_UU,
    REG_RBX,
    REG_R10,
    REG_R11,
    REG_R12,
    REG_R13,
    REG_R14,
    REG_R15,
} reg_t;


struct decl {
    char* name;
    type* type;
    expr* value;
    stmt* code;
    decl* next;
};
    
struct stmt {
    stmt_t kind;
    decl* decl;
    expr* init_expr;
    expr* expr;
    expr* next_expr;
    stmt* body;
    stmt* else_body;
    stmt* next;
};

struct expr {
    expr_t kind;
    expr* left;
    expr* right;
    int value;
    type_t type;
    reg_t reg;
};

struct type {
    type_t kind;
    type* subtype;
    param_list* params;
};

struct param_list {
    char* name;
    type* type;
    param_list* next;
};

extern const char* EXPR_STR_MAP[NUMBER_OF_EXPR];
extern const char* expr_kind_symbol[NUMBER_OF_EXPR];
extern const char* REG_STR_MAP[NUMBER_OF_REG];

expr* expr_create( expr_t kind,
                   expr *left,
                   expr *right );
    
expr* expr_create_value( int value );

decl* decl_create( char* name,
                   type* type,
                   expr* value,
                   stmt* code,
                   decl* next );
           
stmt* stmt_create( stmt_t kind,
                   decl* decl,
                   expr* value,
                   expr* code,
                   expr* next_expr, 
                   stmt* body,
                   stmt* else_body,
                   stmt* next );

type* type_create( type_t kind, 
                   type* subtype,
                   param_list* params );

param_list* param_list_create( char* name,
                               type* type,
                               param_list* next );

#endif