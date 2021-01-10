//
// Created by Ivan Bogatyrev on 12/24/2020.
//

#ifndef LAB_10_01_01_LIST_UTILS_H
#define LAB_10_01_01_LIST_UTILS_H

short append_node(node_t *node);

short create_liked_list(linked_list_t *list);

void *pop_front(node_t **head);

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

int comparator(const void *a, const void *b);

void append(node_t **head_a, node_t **head_b);

node_t *create_node(void *data);

void free_list(node_t *head);

#endif //LAB_10_01_01_LIST_UTILS_H
