//
// Created by Ivan Bogatyrev on 12/12/2020.
//

#ifndef LAB_09_02_STRUCT_CTRL_H
#define LAB_09_02_STRUCT_CTRL_H

struct object *create_object(char *name, double weight, double value);

void free_array(struct object **array, int len);

#endif //LAB_09_02_STRUCT_CTRL_H
