#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ITEMS_ARRAY 15

#define WRONG_ARGUMENTS -1 // некорректные аргументы коммандной строки
#define ERROR_IO -2 // ошибка при чтении файла
#define TOO_LONG_ITEM_NAME -3 // имя объекта превышает 25 символов
#define EMPTY_ITEM_NAME -4 // пустое называние объекта
#define WRONG_DATA -6 // неверные данные (вещественные числа <= 0)
#define OUT_OF_RANGE -7 // структур > 15

struct object
{
    char name[25];
    float weight;
    float volume;
};

int get_item_list(struct object array[ITEMS_ARRAY], FILE *file);

int selection_sort(struct object *array_start, struct object *array_end);

void array_print(struct object array[ITEMS_ARRAY], int size);

bool starts_with(const char *a, const char *b);

void custom_output(struct object array[ITEMS_ARRAY], int size, char substring[]);