#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <sys/time.h>

unsigned long int next = 1;

int rand(void)
{
    next = next * 1103515245;
    return (unsigned int) (next / 65536) * 2768;
}

void srand(unsigned int seed)
{
    next = seed;
}

void array_copy(int *from, int *into, int size)
{
    while (size--)
    {
        *into++ = *from++;
    }
}

int process_1(int array[], int size)
{
    int amount = 0, boolean;
    int new_array[size];
    for (int i = 0; i < size; i++)
    {
        boolean = 0;
        for (int j = 0; j < amount; j++)
        {
            if (array[i] == new_array[j])
            {
                boolean = 1;
            }
        }
        if (boolean == 0)
        {
            new_array[amount] = array[i];
            amount++;
        }
    }
    return amount;
}

int process_2(int *array, int size)
{
    int amount = 0, boolean;
    int new_array[size];
    for (int i = 0; i < size; i++)
    {
        boolean = 0;
        for (int j = 0; j < amount; j++)
        {
            if (*(array + i) == *(new_array + j))
            {
                boolean = 1;
            }
        }
        if (boolean == 0)
        {
            *(new_array + amount) = *(array + i);
            amount++;
        }
    }
    return amount;
}

int process_3(int *array, int size)
{
    int amount = 0, boolean;
    int new_array[size];
    for (int *i = array; i < array + size; i++)
    {
        boolean = 0;
        for (int *j = new_array; j < new_array + amount; j++)
        {
            if (*i == *j)
            {
                boolean = 1;
            }
        }
        if (boolean == 0)
        {
            *(new_array + amount) = *i;
            amount++;
        }
    }
    return amount;
}

int main()
{
    int size = 1000;
    int array[size], array_temp[size];
    struct timeval tv_start, tv_stop;
    double sum = 0;
    int N = 1000000;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
    }

    for (int i = 0; i <= N; i++)
    {
        array_copy(array, array_temp, size);
        gettimeofday(&tv_start, NULL);
        process_1(array_temp, size);
        gettimeofday(&tv_stop, NULL);
        sum += (double) (tv_stop.tv_usec - tv_start.tv_usec) + (double) (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL;
    }
    sum /= N;
    printf("%f microsec\n", sum);
    sum = 0;

    for (int i = 0; i <= N; i++)
    {
        array_copy(array, array_temp, size);
        gettimeofday(&tv_start, NULL);
        process_2(array_temp, size);
        gettimeofday(&tv_stop, NULL);
        sum += (double) (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (double) (tv_stop.tv_usec - tv_start.tv_usec);
    }
    sum /= N;
    printf("%f microsec\n", sum);
    sum = 0;

    for (int i = 0; i <= N; i++)
    {
        array_copy(array, array_temp, size);
        gettimeofday(&tv_start, NULL);
        process_3(array_temp, size);
        gettimeofday(&tv_stop, NULL);
        sum += (double) (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (double) (tv_stop.tv_usec - tv_start.tv_usec);
    }
    sum /= N;
    printf("%f microsec\n", sum);

    return 0;
}
