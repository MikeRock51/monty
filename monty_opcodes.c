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
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (line_token[1][i])
	{
		if (i == 0 && line_token[1][i] == '-')
		{
			i++;
			continue;
		}
		if (line_token[1][i] < '0' || line_token[1][i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
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

/**
 * monty_pall - Prints all the values on a stack
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_pall(stack_t **stack)
{
	stack_t *nav;

	if (*stack == NULL)
		return;
	nav = *stack;
	while (nav->prev != NULL)
		nav = nav->prev;
	while (nav->next)
	{
		fprintf(stdout,"%d\n", nav->n);
		nav = nav->next;
	}
/*	printf("-----------\n");*/
}

/**
 * monty_pint - Prints the value at the top of a stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *nav;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	nav = *stack;
	while (nav->prev != NULL)
		nav = nav->prev;

	printf("pint: %d\n", nav->n);
	printf("-----------\n");
}

/**
 * monty_pop - Removes the top element of a stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nav;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/** nav = (*stack)->next->next;
	* free((*stack)->next);
	* if (nav)
	* 	nav->prev = *stack;
	* (*stack)->next = nav;
	*/

	nav = *stack;
	while (nav->prev != NULL)
		nav = nav->prev;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(nav);
}