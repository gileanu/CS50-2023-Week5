#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node* next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int num = atoi (argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->num = num;
        n->next = list;

        list = n;
    }
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i\n", ptr->num);
        ptr = ptr->next;
    }
    return 0;
}
