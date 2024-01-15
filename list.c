#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *list = malloc(4 * sizeof(int));

    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    list[3] = 4;

    int *temp = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        temp[i] = list[i];
    }
    temp[4] = list[5];

    free(list);
    list = temp;

    if (temp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", temp[i]);
    }
    free(list);
    return 0;
}
