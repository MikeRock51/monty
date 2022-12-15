#include "monty.h"

/**
 * monty_push - Pushes an element to the stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_push(stack_t **stack, unsigned int line_number)
{
        stack_t *new;
        int i = 0;

        new = malloc(sizeof(stack_t));
        if (new == NULL)
                fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
        if (line_token[1] == NULL)
        {
                fprintf(stderr, "L%ld: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }
        while (line_token[1])
        {
                if (i == 0 && line_token[1][i] == '-')
                {
                        i++;
                        continue;
                }
                if (line_token[1][i] < '0' || line_token[1][i] > '9')
                {
                        fprintf(stderr, "L%ld: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                }
                i++;
        }
        new->n = atoi(line_token[1]);
        new->prev = NULL;
        new->next = *stack;
        if (*stack != NULL)
                (*stack)->prev = new;
        *stack = new;
}