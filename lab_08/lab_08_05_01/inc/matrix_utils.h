//
// Created by Ivan Bogatyrev on 12/7/2020.
//

#ifndef LAB_08_05_01_MATRIX_UTILS_H
#define LAB_08_05_01_MATRIX_UTILS_H

void delete_row(int **matrix, int *rows, int columns);

void delete_column(int **matrix, int rows, int *columns);

int copy_old_to_new(int **source_matrix, int **new_matrix, unsigned int rows, unsigned int cols, unsigned int target);

int add_new_row(int **matrix, unsigned int *rows, unsigned int columns, unsigned int target);

int add_new_column(int **matrix, unsigned int rows, unsigned int *columns, unsigned int target);

int find_mult_result(int **matrix_a, int **matrix_b, unsigned int size, unsigned int x, unsigned int y);

void identity_matrix(int **matrix, int size);

void coord_of_min_in_matrix(int **matrix, unsigned int rows, unsigned int columns, unsigned int *x, unsigned int *y);

int find_geom_mean_of_col(int **matrix, unsigned int rows, unsigned int column);

#endif //LAB_08_05_01_MATRIX_UTILS_H
