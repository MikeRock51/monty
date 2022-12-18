#include "monty.h"
/**
 * tokenize - removes unwanted Delimiters
 * @line: line sent from getline function
 * Return: the needed token
*/
char **tokenize(char *line)
{
	char **tokens, *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 2);
	token = strtok(line, DELIMITERS);
	if (token == NULL)
		return (NULL);

	while (i < 2)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIMITERS);
		i++;
	}
  /**
  * token = strtok(NULL, DELIMITERS);
  * if (token != NULL)
  * return (NULL);
  */
	return (tokens);
}
