
#ifndef RK_32_9_LIST_H
#define RK_32_9_LIST_H

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *init_node(int data);

void list_free(node_t *head);

void append(node_t **head_1, node_t **head_2);

node_t *sum(node_t *num1, node_t *num2);

#endif //RK_32_9_LIST_H
