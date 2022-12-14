#include "monty.h"

char **tokenize(char *line)
{
	char **tokens = malloc(sizeof(char *) * 2);
	char *delimiyer = " \n";

	tokens[0] = strtok(line, delimiter);
}
