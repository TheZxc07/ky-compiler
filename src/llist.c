
#include "token.h"

#include <stdlib.h>

typedef struct {
    char* __s_token;
    token_node_t* __p_next;
    token_t __token_type;
} token_node_t;

typedef struct {
    token_node_t* __p_head;
} llist_t;

llist_t* create_token_list(void){
    llist_t* new_token_list = (llist_t*)malloc(sizeof(llist_t));
    new_token_list->__p_head = NULL;
}

void delete_token_list(llist_t* token_list){
    if (token_list == NULL){
        return;
    } 
    token_node_t* p_curr, p_next;
    p_curr = token_list->__p_head;

    while (p_curr != NULL){
        p_next = p_curr->__p_next;
        free(p_curr);
        p_curr = p_next;
    }

    free(token_list);
}

void insert_token(llist_t* token_list, char* s_token, token_t token_type){
    if (token_list == NULL){
        return;
    }

    token_node_t* p_curr;
    token_node_t* new_token = (token_node_t*)malloc(sizeof(token_node_t));
    new_token->__s_token = s_token;
    new_token->__token_type = token_type;
    new_token->__p_next = NULL;

    p_curr = token_list->__p_head;
    
    if (p_curr == NULL){
        token_list->__p_head = new_token
        
    } else {
        while (p_curr->__p_next != NULL){
            p_curr = p_curr->__p_next;
        }
        p_curr->__p_next = new_token;
    }
}