//
// Created by yanag on 6/13/2020.
//

#define ERROR_UNKNOWN -10
#define ERROR_IO -1
#define ERROR_POINTER_ERROR -2

int get_number_by_pos(FILE *file, int *number, size_t position);

int put_number_by_pos(FILE *file, int number, size_t position);

int get_size(FILE *file, size_t *size);

int get_total_len(FILE *file, size_t *len);