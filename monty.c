#include "monty.h"

char **line_token = NULL;

/**
 * checkfile - hekcs if the file filed to open
 * @file: the expected file
 * @filename: the name of the file
*/
void checkfile(FILE *file, char *filename)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
/**
 * argcount - function to monitor the argunemnt count from main
 * @n: number of argument
*/
void argcount(int n)
{
	if (n != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * mallocerror - Prints if malloc fails
*/
void mallocerror(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 * instructionerror - Prints if instruction is unkown
 * @n: line number
*/
void instructionerror(int n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", n, line_token[0]);
	exit(EXIT_FAILURE);
}
/**
 * main - The starting point
 * @ac: keep track of argument count
 * @av: the argument vectors
 * Return: EXIT_SUCCESS (0)
*/

int main(int ac, char *av[])
{
	char *line = NULL;
	FILE *file;
	size_t line_size = 0;
	unsigned int line_number = 0;
	void (*opcode_function)(stack_t **, unsigned int);
	stack_t *stk = malloc(sizeof(stack_t));/*test stack*/

	argcount(ac);

	file = fopen(av[1], "r");
	checkfile(file, av[1]);

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
				mallocerror();
		}
		if (line_token[0][0] == '#')
			continue;
		opcode_function = get_opcode(line_token[0]);
		if (opcode_function != NULL)
			opcode_function(&stk, line_number);
		else
			instructionerror(line_number);

	}
	free_stack(&stk);
	free(line_token);
	return (EXIT_SUCCESS);
}
