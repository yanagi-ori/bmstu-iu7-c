//
// Created by Ivan Bogatyrev on 12/6/2020.
//

#ifndef LAB_08_05_01_MATRIX_OPERATIONS_H
#define LAB_08_05_01_MATRIX_OPERATIONS_H

int squaring(int **matrix, int rows, int columns, int target);

int **matrix_enlargement(int **source_matrix, unsigned int rows, unsigned int columns, unsigned int target);

int **matrix_pow(int **matrix_base, int pow, int size);

int mult_matrices(int **matrix_base, int **matrix, int size);

#endif //LAB_08_05_01_MATRIX_OPERATIONS_H
