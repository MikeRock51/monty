#include "monty.h"

/**
 * monty_queue_mode - Sets the format of data to a stack(LIFO)
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_queue_mode(stack_t **stack)
{
	stack_t *mode = malloc(sizeof(stack_t));
	
	(*stack)->n = QUEUE_MODE;
	(*stack)->prev = NULL;
	(*stack)->next = NULL;

	(void)mode;
}

/**
 * monty_stack_mode - Sets the format of data to a stack(LIFO)
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_stack_mode(stack_t **stack)
{
	stack_t *mode = malloc(sizeof(stack_t));
	
	(*stack)->n = STACK_MODE;
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	(void)mode;
}

/**
 * monty_push_stack - Pushes a node in stack mode
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_push_stack(stack_t **stack)
{
	stack_t *new, *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	head = (*stack)->next;
	new->n = atoi(line_token[1]);
	new->prev = *stack;
	new->next = head;
	if (head != NULL)
		head->prev = new;
	*stack = new;
}

/**
 * monty_push_queue - Pushes a node in queue mode
 * @stack: Double pointer to the top of a stack_t linked list
*/
void monty_push_queue(stack_t **stack)
{
	stack_t *new, *nav;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(line_token[1]);
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	nav = *stack;
	while (nav->next)
		nav = nav->next;
	new->prev = nav;
	nav->next = new;
}
