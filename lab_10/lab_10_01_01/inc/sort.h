//
// Created by Ivan Bogatyrev on 1/10/2021.
//

#ifndef LAB_10_01_01_SORT_H
#define LAB_10_01_01_SORT_H

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

int sort_cmp(const void *a, const void *b);

#endif //LAB_10_01_01_SORT_H
