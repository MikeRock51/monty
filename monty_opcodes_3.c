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

/**
 * monty_sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_sub(stack_t **stack, unsigned int line_number)
{
        stack_t *nav;
        unsigned int stack_length = count_elements(stack);
        int sub_result;

        if (stack_length < 2)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        nav = (*stack);
        nav = nav->next;
        sub_result = nav->n - (*stack)->n;
        nav = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = sub_result;
        free(nav);
}

/**
 * monty_div - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_div(stack_t **stack, unsigned int line_number)
{
        stack_t *nav;
        unsigned int stack_length = count_elements(stack);
        int div_result;

        if (stack_length < 2)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        nav = (*stack);
        nav = nav->next;
        if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                exit(EXIT_FAILURE);
        }
        div_result = nav->n / (*stack)->n;
        nav = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = div_result;
        free(nav);
}

/**
 * monty_mul - Multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_mul(stack_t **stack, unsigned int line_number)
{
        stack_t *nav;
        unsigned int stack_length = count_elements(stack);
        int mul_result;

        if (stack_length < 2)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        nav = (*stack);
        nav = nav->next;
        mul_result = nav->n * (*stack)->n;
        nav = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        (*stack)->n = mul_result;
        free(nav);
}