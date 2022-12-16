#include "monty.h"
/**
 * get_opcode - Matches instruction with corresponding function
 * @opcode: The instruction to match
 * 
 * Return: A pointer to the matched opcode function
*/
void (*get_opcode(char *opcode))(stack_t **, unsigned int)
{
        instruction_t opcode_list[] = {
                {"push", monty_push},
                {"pall", monty_pall},
                {"pint", monty_pint},
                {"pop", monty_pop},
                {"swap", monty_swap},
                {"add", monty_add},
                {NULL, NULL}
        };
        int i = 0;

        while (opcode_list[i].opcode)
        {
                if (strcmp(opcode, opcode_list[i].opcode) == 0)
                {
                        return(opcode_list[i].f);
                }
                i++;
        }
        return (NULL);
}

/**
 * count_elements - Counts the number of elements on the stack
 * @stack: Double pointer to the top of a stack_t linked list
 *
 * Return: Number of elements on the stack or 0 if stack is empty
*/
unsigned int count_elements(stack_t **stack)
{
        stack_t *nav;
        unsigned int stack_length = 0;

        if (*stack == NULL)
                return (stack_length);

        nav = (*stack);
        while (nav->prev != NULL)
                nav = nav->prev;
        while (nav->next)
        {
                stack_length++;
                nav = nav->next;
        }
        return (stack_length);
}