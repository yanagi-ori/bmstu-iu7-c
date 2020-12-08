//
// Created by Ivan Bogatyrev on 11/10/2020.
//

#ifndef LAB_07_1_IO_H
#define LAB_07_1_IO_H

#endif //LAB_07_1_IO_H

short int elements_counter(FILE *file_stream, unsigned short int *counter);

short int array_filling(FILE *file_stream, int *array_pointer, const int *const array_end_pointer);

short int create_new_file(FILE *file_stream, char *name);

short int write_new_data(FILE *file_stream, int *array_b, const int *array_e);

