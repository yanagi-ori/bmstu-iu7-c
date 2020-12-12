//
// Created by Ivan Bogatyrev on 12/12/2020.
//

#ifndef LAB_09_02_IO_H
#define LAB_09_02_IO_H

#include <stdio.h>

void array_print(struct object **array, int size);

int get_item_list(struct object ***array, FILE *file, int *length);

void custom_output(struct object **array, int size, char *substring);

#endif //LAB_09_02_IO_H
