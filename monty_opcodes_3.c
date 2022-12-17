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
		fprintf(stderr, "L%u: can't pchar, empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 && (*stack)->n > 255)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
