#ifndef LAB_09_02_UTILS_H
#define LAB_09_02_UTILS_H

int selection_sort(struct object **array_start, struct object **array_end);

int starts_with(const char *a, const char *b);

struct object **add_to_array(struct object **array, struct object *new_item, int *len);

#endif
