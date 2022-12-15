#include "monty.h"

char **tokenize(char *line)
{
	char **tokens = malloc(sizeof(char *) * 2), *token;
	int i = 0;

	token = strtok(line, DELIMITERS);
	
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIMITERS);
		i++;
	}
	return(tokens);
}