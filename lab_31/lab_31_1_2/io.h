//
// Created by Ivan Bogatyrev on 11/14/2020.
//

#ifndef LAB_31_1_2_IO_H
#define LAB_31_1_2_IO_H

int get_matrix_size(FILE *file, int *rows, int *columns);

int get_matrix(FILE *file, int **matrix, int rows, int columns);

#endif //LAB_31_1_2_IO_H