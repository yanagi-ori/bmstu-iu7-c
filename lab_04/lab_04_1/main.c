#include <string.h>

#include "my_strrchr.h"

int main()
{
    char string[] = "How I could guess it?";
    char c = 'u';

    if (my_strrchr(string, c) == strrchr(string, c))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
