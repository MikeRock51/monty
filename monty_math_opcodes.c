#include "monty.h"

/**
 * monty_add - Adds the two top elements of the stack
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *second, *third;
	unsigned int stack_length = count_elements(stack);
	int add_result;

	if (stack_length < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = (*stack)->next;
	third = second->next;
	add_result = third->n + second->n;
	second->n = add_result;
	second->next = third->next;
	third->next->prev = second;
	free(third);
}

/**
 * monty_sub - Subtracts the top element of the stack
 * from the second top element
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *second, *third;
	unsigned int stack_length = count_elements(stack);
	int sub_result;

	if (stack_length < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = (*stack)->next;
	third = second->next;
	sub_result = second->n - third->n;
	second->n = sub_result;
	second->next = third->next;
	third->next->prev = second;
	free(third);
}

/**
 * monty_div - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *second, *third;
	unsigned int stack_length = count_elements(stack);
	int div_result;

	if (stack_length < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = (*stack)->next;
	third = second->next;
	if (second->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div_result = third->n / second->n;
	second->n = div_result;
	second->next = third->next;
	third->next->prev = second;
	free(third);

}

/**
 * monty_mul - Multiplies the second top element
 *  of the stack with the top element
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *second, *third;
	unsigned int stack_length = count_elements(stack);
	int mul_result;

	if (stack_length < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = (*stack)->next;
	third = second->next;
	mul_result = third->n * second->n;
	second->n = mul_result;
	second->next = third->next;
	third->next->prev = second;
	free(third);
}

/**
 * monty_mod -  Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Double pointer to the top of a stack_t linked list
 * @line_number: Current line number
*/
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *second, *third;
	unsigned int stack_length = count_elements(stack);
	int mod_result;

	if (stack_length < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = (*stack)->next;
	third = second->next;
	if (second->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod_result = third->n % second->n;
	second->n = mod_result;
	second->next = third->next;
	third->next->prev = second;
	free(third);
}
