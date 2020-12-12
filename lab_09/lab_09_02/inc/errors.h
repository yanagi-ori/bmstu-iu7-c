//
// Created by Ivan Bogatyrev on 12/12/2020.
//

#ifndef LAB_09_02_ERRORS_H
#define LAB_09_02_ERRORS_H


#define WRONG_ARGUMENTS 1 // некорректные аргументы коммандной строки
#define ERROR_IO 2 // ошибка при чтении файла
#define TOO_LONG_ITEM_NAME 3 // имя объекта превышает 25 символов
#define EMPTY_ITEM_NAME -4 // пустое называние объекта
#define WRONG_DATA 6 // неверные данные (вещественные числа <= 0)
#define OUT_OF_RANGE -7 // структур > 15
#define MEMORY_ALLOCATION_ERROR 8


#define EPS 1E-10
#endif //LAB_09_02_ERRORS_H
