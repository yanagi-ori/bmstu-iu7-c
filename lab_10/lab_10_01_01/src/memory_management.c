//
// Created by Ivan Bogatyrev on 12/23/2020.
//

#include <stdlib.h>
#include "../inc/struct.h"
#include "../inc/memory_management.h"
#include "../inc/utils.h"


student_t *create_data(char *surname, char *name, char *year, char *group)
{
    student_t *new_student = (student_t *) malloc(sizeof(student_t));
    if (!new_student)
    {
        return NULL;
    }

    new_student->surname = my_strdup(surname);
    new_student->name = my_strdup(name);
    new_student->year = my_strdup(year);
    new_student->group = my_strdup(group);

    return new_student;
}

void free_data(student_t *data)
{

    free(data->surname);
    free(data->name);
    free(data->year);
    free(data->group);

    free(data);

}