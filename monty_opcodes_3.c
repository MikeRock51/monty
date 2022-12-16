#include "monty.h"

/**
 * monty_add - Adds the two top elements of the stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_add(stack_t **stack, unsigned int line_number)
{
        stack_t *nav;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        nav = (*stack);
        while (nav->prev != NULL)
                nav = nav->prev;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        nav->prev = *stack;
        nav->next = (*stack)->next;
        (*stack)->next->prev = nav;
        (*stack)->next = nav;
}