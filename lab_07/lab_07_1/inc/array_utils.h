//
// Created by Ivan Bogatyrev on 11/10/2020.
//

#ifndef LAB_07_1_ARRAY_UTILS_H
#define LAB_07_1_ARRAY_UTILS_H

short int free_memory(const int *pointer);

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

int compare(const void *x1, const void *x2);

#endif //LAB_07_1_ARRAY_UTILS_H
