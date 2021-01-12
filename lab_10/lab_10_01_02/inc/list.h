//
// Created by Ivan Bogatyrev on 1/12/2021.
//

#ifndef LAB_10_01_02_LIST_H
#define LAB_10_01_02_LIST_H

typedef struct node
{
    int coefficient;
    short power;
    struct node *next;
} node_t;

node_t *create_node(int temp_coef, short temp_power);

void free_list(node_t *head);

void append(node_t **head_a, node_t **head_b);

int get_len(node_t *head);

void list_copy(node_t *head, node_t **head_copy);

node_t *find_var_degree(node_t *head, node_t *node);

int insert_node(node_t **head, node_t *node);

#endif //LAB_10_01_02_LIST_H
