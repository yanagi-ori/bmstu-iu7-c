/*
Для тестирования написан ./test.sh

Выбранные целочисленный тип - int
Алгоритм сортировки - вставками
«Направление» упорядочивания - по-возрастанию.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define POINTER_ERROR -1
#define DATA_ERROR -2
#define LAUNCH_ERROR -3
#define IO_ERROR -4
#define SEEK_ERROR -5

#define CREATE_FILE_MODE 1
#define OUTPUT_FILE_MODE 2
#define SORT_FILE_MODE   3

#define MAX_RANDOM_INT 100
#define MIN_RANDOM_INT -100

int file_size(FILE *file, int *size)
{
    int err = 0;
    if (fseek(file, 0, SEEK_END))
    {
        err = SEEK_ERROR;
    }
    if (!err)
    {
        *size = ftell(file);
    }
    if (!err && *size < 0)
    {
        return SEEK_ERROR;
    }

    return err || fseek(file, 0, SEEK_SET);
}

int get_number_by_pos(FILE *file, size_t pos, int *number)
{
    int err = fseek(file, pos * sizeof(int), SEEK_SET) < 0;
    if (!err)
    {
        err = fread(number, sizeof(int), 1, file) != 1;
    }
    return err;
}

int put_number_by_pos(FILE *file, size_t pos, int number)
{
    int err = fseek(file, pos * sizeof(int), SEEK_SET) < 0;
    if (!err)
    {
        err = fwrite(&number, sizeof(int), 1, file) != 1;
    }
    return err;
}

int create_random_file(FILE *file, size_t count)
{
    int err = 0;

    if (!file)
    {
        err = IO_ERROR;
    }

    srand(time(0));

    for (size_t i = 0; i < count && !err; i++)
    {
        int random_number = rand() % (MAX_RANDOM_INT - MIN_RANDOM_INT + 1) + MIN_RANDOM_INT;
        err = fwrite(&random_number, sizeof(int), 1, file) != 1;
    }

    return err;
}

int output_file(FILE *file)
{
    int err = 0;
    int size;
    int num;

    if (!file)
    {
        err = IO_ERROR;
    }

    if (!err)
    {
        err = file_size(file, &size);
    }

    if (!err)
    {
        err = size <= 0 || size % sizeof(int);
    }

    if (!err)
    {
        for (size_t i = 0; i < (size / sizeof(int)) && !err; i++)
        {
            if (fread(&num, sizeof(int), 1, file) == 1)
            {
                printf("%d ", num);
            }
            else
            {
                err = 1;
            }
        }
        printf("\n");
    }

    return err;
}


int sort_file(FILE *file)
{
    int err = 0;
    int size;

    if (!file)
    {
        err = IO_ERROR;
    }

    if (!err)
    {
        err = file_size(file, &size);
    }

    if (!err)
    {
        err = size <= 0 || size % sizeof(int);
    }

    if (!err)
    {
        size /= sizeof(int);

        int i, key, j;
        for (i = 1; i < size; i++)
        {
            int current;
            j = i;
            err = get_number_by_pos(file, i, &key);
            if (!err)
            {
                err = get_number_by_pos(file, j - 1, &current);
            }

            while (!err && j > 0 && current > key)
            {
                err = put_number_by_pos(file, j, current);
                j--;
                if (j && !err)
                {
                    err = get_number_by_pos(file, j - 1, &current);
                }
            }

            if (!err)
            {
                put_number_by_pos(file, j, key);
            }
        }
    }

    return err;
}


int get_mode(int argc, char **argv, int *mode)
{
    if (!argv || !mode)
    {
        return POINTER_ERROR;
    }

    int err = 0;
    *mode = 0;

    if (argc != 3 && argc != 4)
    {
        err = LAUNCH_ERROR;
    }

    if (!err)
    {
        if (!strcmp(argv[1], "c"))
        {
            *mode = CREATE_FILE_MODE;
        }
        if (!strcmp(argv[1], "p"))
        {
            *mode = OUTPUT_FILE_MODE;
        }
        if (!strcmp(argv[1], "s"))
        {
            *mode = SORT_FILE_MODE;
        }
        if (!(*mode))
        {
            err = LAUNCH_ERROR;
        }
    }

    return err;
}

int main(int argc, char **argv)
{
    int mode = 0;

    int err = get_mode(argc, argv, &mode);

    size_t count = 0;
    if (!err)
    {
        FILE *file = 0;
        switch (mode)
        {
            case CREATE_FILE_MODE:
                err = sscanf(argv[2], "%lu", &count) != 1;
                file = fopen(argv[3], "wb");
                if (!err)
                {
                    err = create_random_file(file, count);
                }
                break;
            case OUTPUT_FILE_MODE:
                file = fopen(argv[2], "rb");
                err = output_file(file);
                break;
            case SORT_FILE_MODE:
                file = fopen(argv[2], "rb+");
                err = sort_file(file);
                break;
        }
        if (file)
        {
            fclose(file);
        }
    }

    if (err)
    {
        printf("Error \n");
    }

    return err;
}
