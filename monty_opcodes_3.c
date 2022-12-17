#include "monty.h"

/**
 * monty_pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the top element of the stack
 * @line_number: Current line number
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 && (*stack)->n > 255)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * monty_pstr - Prints each character of a stack to form a string
 * @stack: Double pointer to the top element of the stack
 * @line_number: Current line number
 */
void monty_pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *nav;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	nav = *stack;
	while (nav)
	{	
		if ((nav->n < 0 && nav->n > 255) || nav->n == 0)
			break;
		printf("%c", nav->n);
		nav = nav->next;
	}
	printf("\n");
}

