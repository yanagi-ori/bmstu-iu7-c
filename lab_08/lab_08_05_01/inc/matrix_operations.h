//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#ifndef LAB_08_05_01_MATRIX_OPERATIONS_H
#define LAB_08_05_01_MATRIX_OPERATIONS_H

int squaring(int **matrix, unsigned int rows, unsigned int columns, unsigned int target);

int **matrix_enlargement(int **source_matrix, unsigned int rows, unsigned int columns, unsigned int target);

int **multiply_matrices(int **matrix_a, int **matrix_b, unsigned int size);

#endif //LAB_08_05_01_MATRIX_OPERATIONS_H
