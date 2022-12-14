#include "monty.h"

char **tokenize(char *line)
{
	char **tokens = malloc(sizeof(char *) * 2), *token;
	char *delimiter = " \n";
	int i = 0;

	token = strtok(line, delimiter);
	
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	return(tokens);
}