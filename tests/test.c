#include <stdlib.h>
#include <stdio.h>

int main()
{
        typedef struct node {
                int n;
                struct node *next;
        } list_t;

        list_t *num_list, *ptr = malloc(sizeof(list_t)), *temp;
        num_list = malloc(sizeof(list_t));

        num_list->n = 10;
        num_list->next = NULL;

        ptr->n = 50;
        num_list->next = ptr;
        ptr->next = NULL;

        temp = num_list;

        while (temp != NULL)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }




}