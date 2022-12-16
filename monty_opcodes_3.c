#include "monty.h"

/**
 * monty_add - Adds the two top elements of the stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_add(stack_t **stack, unsigned int line_number)
{
        stack_t *nav;
        unsigned int stack_length = count_elements(stack);
        int add_result;

        if (stack_length < 2)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        nav = (*stack);
        nav = nav->next;
        add_result = (*stack)->n + nav->n;
        nav = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = add_result;
        free(nav);
}