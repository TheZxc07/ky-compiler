#include "token.h"
#include "llist.h"
#include <stdio.h>
#include <string.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main() {
    llist_t* token_list = create_token_list();
    yyin = fopen("./test_src/program.c","r");
    if(!yyin) {
        printf("could not open program.c!\n");
        return 1;
    }
    while(1) {
        token_t t = yylex();
        if(t==TOKEN_EOF) break;
            //printf("token: %s text: %s\n",TOKEN_STR_MAP[t],yytext);
        insert_token(token_list, strdup(yytext), t);
    }

    print_list(token_list);
}
