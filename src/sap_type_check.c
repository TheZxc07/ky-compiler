#include "sap_type_check.h"

type_t sap_expr_typecheck( expr* expr ){
    if (expr->type == TYPE_INT) { return TYPE_INT; }
    if (expr->type == TYPE_FLOAT) { return TYPE_FLOAT; }
    type_t left_expr_type = sap_expr_typecheck(expr->left);
    type_t right_expr_type = sap_expr_typecheck(expr->right);

    if (left_expr_type != right_expr_type){
        return TYPE_ERROR;
    }
}