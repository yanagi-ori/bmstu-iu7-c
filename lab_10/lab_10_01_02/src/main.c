#include <stdio.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/list.h"
#include "../inc/io.h"
#include "../inc/operations.h"

int main()
{
    char buffer[4];
    int rc = 0;
    int rv = scanf("%3s", buffer);
    getc(stdin);
    if (rv == 1)
    {
        node_t *head = NULL;
        if (strcmp("val", buffer) == 0)
        {
            rc = get_line(&head);
            if (rc == 0)
            {
                int arg;
                rv = scanf("%d", &arg);
                if (rv == 1)
                {
                    printf("%d", val(head, arg));
                }
                else
                {
                    rc = IO_ERROR;
                }
                free_list(head);
            }
        }
        else if (strcmp("ddx", buffer) == 0)
        {
            rc = get_line(&head);
            if (rc == 0)
            {
                node_t *new_head = ddx(head);
                print_list(new_head);
                printf("L");
                free_list(head);
                free_list(new_head);
            }
        }
        else if (strcmp("sum", buffer) == 0)
        {
            rc = get_line(&head);
            if (rc == 0)
            {
                node_t *head2 = NULL;
                rc = get_line(&head2);
                if (rc == 0)
                {
                    node_t *result = sum(head, head2);
                    if (result)
                    {
                        print_list(result);
                        printf("L");
                        free_list(result);
                    }
                    free_list(head2);
                }
                free_list(head);
            }
        }
        else if (strcmp("dvd", buffer) == 0)
        {
            rc = get_line(&head);
            if (rc == 0)
            {
                node_t *head_even = NULL;
                node_t *head_odd = NULL;
                dvd(head, &head_even, &head_odd);
                print_list(head_even);
                printf("L\n");
                print_list(head_odd);
                printf("L");
                free_list(head_odd);
                free_list(head_even);
                free_list(head);
            }
        }
        else
        {
            rc = WRONG_MENU_ITEM;
        }
    }
    else
    {
        rc = IO_ERROR;
    }

    return rc;
}
