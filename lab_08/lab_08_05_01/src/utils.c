//
// Created by Ivan Bogatyrev on 12/6/2020.
//

int min(unsigned int a, unsigned int b)
{
    if (a - b >= 0)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void coord_of_min_in_matrix(int **matrix, unsigned int rows, unsigned int columns, unsigned int *x, unsigned int *y)
{
    int min = matrix[0][0];

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < columns; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                *x = i;
                *y = j;
            }
        }
    }
}