#ifndef SAP_CODEGEN_H
#define SAP_CODEGEN_H

#include "expr.h"
#include <stdio.h>

extern int reg_alloc_map[NUMBER_OF_REG];

reg_t reg_alloc();
void reg_free(reg_t reg);
void expr_codegen(expr* ast);
void __expr_codegen(expr* ast, FILE* fp);

#endif