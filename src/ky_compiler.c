#include "token.h"
#include "llist.h"
#include "llg_parser.h"
#include "expr.h"
#include <stdio.h>
#include <string.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main() {
    llist_t* token_list = create_token_list();
    yyin = fopen("./test_src/simple_prog.c","r");
    if(!yyin) {
        printf("could not open program.c!\n");
        return 1;
    }
    while(1) {
        token_t t = yylex();
        insert_token(token_list, strdup(yytext), t);
        if(t==TOKEN_EOF) break;
            //printf("token: %s text: %s\n",TOKEN_STR_MAP[t],yytext);
    }
    print_list(token_list);
    expr* ast = parse_prog(token_list);
    if(ast){
        printf("This is a valid program!\n");
    } else {
        printf("This is NOT a valid program!\n");
    }
    print_ast(ast);
}
