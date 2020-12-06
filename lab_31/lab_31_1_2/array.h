//
// Created by Ivan Bogatyrev on 11/14/2020.
//

#ifndef LAB_31_1_2_ARRAY_H
#define LAB_31_1_2_ARRAY_H

int **create_array(int rows, int columns);

void free_matrix(int **pointers);

int find_number(int **matrix, int *number, int size);

#endif //LAB_31_1_2_ARRAY_H