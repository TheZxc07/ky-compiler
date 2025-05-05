#include "token.h"
#include "llist.h"

llist_t* create_token_list(void){
    llist_t* new_token_list = (llist_t*)malloc(sizeof(llist_t));
    new_token_list->__p_head = NULL;
    return new_token_list;
}

void delete_token_list(llist_t* token_list){
    if (token_list == NULL){
        return;
    } 
    token_node_t* p_curr, *p_next;
    p_curr = token_list->__p_head;

    while (p_curr != NULL){
        p_next = p_curr->__p_next;
        if (p_curr->__s_token != NULL){
            free(p_curr->__s_token);
        }
        free(p_curr);
        p_curr = p_next;
    }

    free(token_list);
    token_list = NULL;
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
        token_list->__p_head = new_token;
        
    } else {
        while (p_curr->__p_next != NULL){
            p_curr = p_curr->__p_next;
        }
        p_curr->__p_next = new_token;
    }
}

void print_list(llist_t* token_list){
    if (token_list == NULL){
        return;
    }

    token_node_t* p_curr;
    p_curr = token_list->__p_head;

    if (p_curr == NULL){
        return;
    } else{
        while (p_curr != NULL){
            printf("token: %s text: %s\n",TOKEN_STR_MAP[p_curr->__token_type],p_curr->__s_token);
            p_curr = p_curr->__p_next;
        }
    }
}

void pop_front(llist_t* token_list, token_st* out){
    if (token_list == NULL){
        return;
    }
    //printf("BEFORE POPPING\n");
    //print_list(token_list);
    token_node_t* p_front = token_list->__p_head;

    if (p_front == NULL){
        out = NULL;
    } else {
        out->s_token = p_front->__s_token;
        out->token_type = p_front->__token_type;
        token_list->__p_head = p_front->__p_next;
    }
    //printf("AFTER POPPING\n");
    //print_list(token_list);
}

void push_front(llist_t* token_list, token_st* in){
    if (token_list == NULL){
        return;
    }
    //printf("BEFORE PUSHING\n");

    //print_list(token_list);
    token_node_t* new_token = (token_node_t*)malloc(sizeof(token_node_t));

    new_token->__s_token = in->s_token;
    new_token->__token_type = in->token_type;
    new_token->__p_next = NULL;

    if(token_list->__p_head == NULL){
        token_list->__p_head = new_token;
    } else {
        new_token->__p_next = token_list->__p_head;
        token_list->__p_head = new_token; 
    }
    //printf("AFTER PUSHING\n");
    //print_list(token_list);
}