#include <stdlib.h>
#include <stdio.h>

typedef struct token_node token_node_t;
typedef struct llist llist_t;

struct token_node {
    char* __s_token;
    token_node_t* __p_next;
    token_t __token_type;
};

struct token_st {
    char* s_token;
    token_t token_type;
};

struct llist {
    token_node_t* __p_head;
};

llist_t* create_token_list(void);
void delete_token_list(llist_t* token_list);
void insert_token(llist_t* token_list, char* s_token, token_t token_type);

void pop_front(llist* token_list, token_st*);
void push_front(llist* token_list, token_st*);

