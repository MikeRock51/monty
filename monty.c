#include "monty.h"

char **line_token = NULL;

int main(int ac, char *av[])
{
	char *line = NULL;
	FILE *file;
	size_t line_number = 0;
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

	while (fgets(line, sizeof(line), file) != NULL)
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
		if (strcmp(line_token[0], "push") == 0)
			monty_push(&stk, line_number);
		else if (strcmp(line_token[0], "pall") == 0)
		    monty_pall(&stk);
		else if (strcmp(line_token[0], "pop") == 0)
		    monty_pop(&stk, line_number);
		else if (strcmp(line_token[0], "pint") == 0)
		    monty_pint(&stk, line_number);
	}
	return (EXIT_SUCCESS);
}
