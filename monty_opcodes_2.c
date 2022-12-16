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