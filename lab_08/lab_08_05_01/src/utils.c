//
// Created by Ivan Bogatyrev on 12/6/2020.
//

unsigned int min(unsigned int a, unsigned int b)
{
    if (a >= b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

unsigned int max(unsigned int a, unsigned int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int abs(int num)
{
    if (num < 0)
    {
        num *= (-1);
    }
    return num;
}