#include "token.h"
#include "llist.h"
#include "llg_parser.h"
#include "expr.h"
#include "sap_type_check.h"
#include "sap_codegen.h"
#include <stdio.h>
#include <string.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main() {
    llist_t* token_list = create_token_list(); // token queue
    yyin = fopen("./test_src/simple_prog.kysap","r"); // open sap program
    if(!yyin) {
        printf("could not open program.kysap!\n");
        return 1;
    }
    while(1) {
        token_t t = yylex(); // scan next token in filestream according to RE rules
        insert_token(token_list, strdup(yytext), t); // append to token queue
        if(t==TOKEN_EOF) break;
            //printf("token: %s text: %s\n",TOKEN_STR_MAP[t],yytext);
    }
    print_list(token_list); 
    expr* ast = parse_prog(token_list); // create AST, AST == NULL if program is invalid
    if(ast){  // program is valid according to the grammar
        printf("This is a valid program!\n");
        print_ast(ast);

        type_t sap_type = sap_expr_typecheck(ast); // basic semantic analysis makes sure you dont mix floats and ints
    
        if (sap_type == TYPE_ERROR){
            printf("Semantic analysis error!\n");
        } else { // program is semantically valid according to basic type checking
            printf("Semantic analysis completed!\n");
            expr_codegen(ast); // perform basic codegen
        }
    } else {
        printf("This is NOT a valid program!\n");
    }
}
