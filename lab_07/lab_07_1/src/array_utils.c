//
// Created by Ivan Bogatyrev on 11/10/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "../inc/errors.h"


short int free_memory(const int *pointer)
{
    free((void *) pointer);
    return 0;
}

void copy_arr(int **dst_start, int **dst_end, const int *current_pointer, int amount)
{
    while (*dst_start < *dst_end)
    {
        **dst_start = *current_pointer++;
        (*dst_start)++;
    }
    *dst_start -= (amount);
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src || pb_src >= pe_src)
    {
        return WRONG_DATA;
    }

    int has_negative = 0;
    int amount;

    const int *last_negative = pe_src - 1;
    const int *current_pointer = pb_src;

    while (current_pointer < pe_src)
    {
        if (*current_pointer < 0)
        {
            has_negative = 1;
            last_negative = current_pointer;
        }
        current_pointer++;
    }

    amount = last_negative - pb_src + 1 - has_negative;

    if (amount == 0)
    {
        return WRONG_DATA;
    }

    *pb_dst = malloc(sizeof(int) * amount);
    if (pb_dst == NULL)
    {
        return ARRAY_MEMORY_ALLOCATION_ERROR;
    }

    *pe_dst = *pb_dst + amount;

    copy_arr(pb_dst, pe_dst, pb_src, amount);

    return 0;
}

int compare_int(const void *x1, const void *x2)
{
    return (*(int *) x1 - *(int *) x2);
}

void swap(void *x, void *y, unsigned int size)
{
    char *temp_x = x, *temp_y = y;
    do
    {
        char tmp = *temp_y;
        *temp_y++ = *temp_x;
        *temp_x++ = tmp;
    } while (--size > 0);
}

void mysort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *))
{
    char *right = (char *) base + size * (nmemb);

    for (char *left = (char *) base + size; left < right;)
    {
        for (char *i = left; i > (char *) base;)
        {
            char *temp = i - size;
            if ((compare)((void *) i, (void *) temp) <= 0)
            {
                swap((void *) i, (void *) temp, size);
            }
            i = i - size;
        }
        left = left + size;
    }
}


