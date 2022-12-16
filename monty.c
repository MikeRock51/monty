#include "monty.h"

char **line_token = NULL;

int main(int ac, char *av[])
{
        char *line = NULL;
        FILE *file;
        size_t line_size = 0;
        unsigned int line_number = 0;
        void (*opcode_function)(stack_t **, unsigned int);
        stack_t *stk = malloc(sizeof(stack_t));/*test stack*/

        if (ac != 2)
        {
            fprintf(stderr, "USAGE: monty file\n");
            exit(EXIT_FAILURE);
        }

        file = fopen(av[1], "r");
        if (file == NULL)
        {
            fprintf(stderr, "Error: Can't open file %s\n", av[1]);
            exit(EXIT_FAILURE);
        }

        line = malloc(sizeof(char *));
        
        while (getline(&line, &line_size, file) != -1)
        {
                line_number++;
                line_token = tokenize(line);
                if (line_token == NULL)
                {
                        if (check_empty_line(line, DELIMITERS) == 1)
                                continue;
                        else
                        {
                                fprintf(stderr, "Error: malloc failed\n");
                                exit(EXIT_FAILURE);
                        }
                }
                if (line_token[0][0] == '#')
                        continue;
                opcode_function = get_opcode(line_token[0]);
                if (opcode_function != NULL)
                    opcode_function(&stk, line_number);
                else
                {
                        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, line_token[0]);
                        exit(EXIT_FAILURE);
                }
                /* if (strcmp(line_token[0], "push") == 0)
                        monty_push(&stk, line_number);
                else if (strcmp(line_token[0], "pall") == 0)
                    monty_pall(&stk, line_number);
                else if (strcmp(line_token[0], "pop") == 0)
                    monty_pop(&stk, line_number);
                else if (strcmp(line_token[0], "pint") == 0)
                    monty_pint(&stk, line_number);
                */
        }
        free_stack(&stk);
        free(stk);
        free(line_token);
        return (EXIT_SUCCESS);
}