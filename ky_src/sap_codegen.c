#include "sap_codegen.h"

int reg_alloc_map[NUMBER_OF_REG] = {-1,0,0,0,0,0,0,0};

reg_t reg_alloc(){
    for (int i = 0; i < NUMBER_OF_REG; i++){
        if (reg_alloc_map[i] == 0){
            reg_alloc_map[i] = -1;
            return i;
        }
    }
    return 0;
}

void reg_free(reg_t reg){
    reg_alloc_map[reg] = 0;
}

void expr_codegen(expr* ast){

    FILE* fp = fopen("out.as", "w");
    fprintf(fp, "\t.globl _start\n\t.text\n\n_start:\n");
    __expr_codegen(ast, fp);
    fprintf(fp,"\tMOVQ $60, %%rax\n\tMOVQ %s, %%rdi\n\tSYSCALL\n", REG_STR_MAP[ast->reg]);
}

void __expr_codegen(expr* e, FILE* fp){
    if (e == NULL){
        return;
    }

    __expr_codegen(e->left, fp);
    __expr_codegen(e->right, fp);

    switch(e->kind){
        case EXPR_VALUE:
            e->reg = reg_alloc();
            fprintf(fp, "\tMOVQ $%d, %s\n", e->value.i, REG_STR_MAP[e->reg]);
            break;
        case EXPR_ADD:
            fprintf(fp, "\tADDQ %s, %s\n", REG_STR_MAP[e->right->reg], REG_STR_MAP[e->left->reg]);
            reg_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_SUBTRACT:
            fprintf(fp, "\tSUBQ %s, %s\n", REG_STR_MAP[e->right->reg], REG_STR_MAP[e->left->reg]);
            reg_free(e->right->reg);
            e->reg = e->left->reg;
            break;
        case EXPR_MULTIPLY:
            fprintf(fp, "\tMOVQ %s, %%rax\n", REG_STR_MAP[e->left->reg]);
            fprintf(fp, "\tIMUL %s\n", REG_STR_MAP[e->right->reg]);
            fprintf(fp, "\tMOVQ %%rax, %s\n", REG_STR_MAP[e->right->reg]);
            reg_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        case EXPR_DIVIDE:
            fprintf(fp, "\tMOVQ %s, %%rax\n", REG_STR_MAP[e->left->reg]);
            fprintf(fp, "\tCQO\n");
            fprintf(fp, "\tIDIVQ %s\n", REG_STR_MAP[e->right->reg]);
            fprintf(fp, "\tMOVQ %%rax, %s\n", REG_STR_MAP[e->right->reg]);
            reg_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        default:
            printf("temp\n");
            break;
    }
}