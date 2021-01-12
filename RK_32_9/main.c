#include <stdio.h>
#include "errors.h"
#include "list.h"
#include "io.h"

int main(int argc, char **argv)
{
    int rc = 0;
    if (argc == 3)
    {
        FILE *file1 = fopen(argv[1], "r");
        FILE *file2 = fopen(argv[2], "w");
        if (file1 && file2)
        {
            node_t *num1 = NULL;
            rc = read_file(file1, &num1);

            if (rc == 0)
            {
                printf("Got first number: ");
                print_num(stdout, num1);
                node_t *num2 = NULL;
                rc = read_file(file1, &num2);

                if (rc == 0)
                {
                    printf("Got second number: ");
                    print_num(stdout, num2);

                    node_t *result = sum(num1, num2);
                    print_num(stdout, result);
                    print_num(file2, result);
                    list_free(result);
                }
                else
                {
                    list_free(num1);
                }
            }

            fclose(file1);
            fclose(file2);
        }
        else
        {
            if (file1)
            {
                fclose(file1);
            }
            if (file2)
            {
                fclose(file2);
            }
            rc = IO_ERROR;
        }

    }
    else
    {
        rc = WRONG_ARGUMENT;
    }
    return rc;
}
