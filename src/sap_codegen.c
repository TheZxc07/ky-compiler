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

void expr_codegen(expr* e){
    if (e == NULL){
        return;
    }

    expr_codegen(e->left);
    expr_codegen(e->right);

    switch(e->kind){
        case EXPR_VALUE:
            e->reg = reg_alloc();
            printf("MOVQ %%%d, %s\n", e->value.i, REG_STR_MAP[e->reg]);
            break;
        case EXPR_ADD:
            printf("ADDQ %s, %s\n", REG_STR_MAP[e->left->reg], REG_STR_MAP[e->right->reg]);
            reg_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        case EXPR_SUBTRACT:
            printf("SUBQ %s, %s\n", REG_STR_MAP[e->left->reg], REG_STR_MAP[e->right->reg]);
            reg_free(e->left->reg);
            e->reg = e->right->reg;
            break;
        default:
            printf("temp\n");
            break;
    }
}