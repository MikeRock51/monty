#include "monty.h"

/**
 * check_empty_line - Checks if a line of file is empty or contains only delimiters
 * @line: Line to check
 * @delimiter: Delimiting characters
 * 
 * Return: 0 if line contains valid texts.
 * Return 1 otherwise
*/
int check_empty_line(char *line, char *delimiter)
{
        int i = 0, j;

        while (line[i])
        {
                j = 0;
                while (delimiter[j] != line[i])
                        j++;
                if (delimiter[j] == '\0')
                        return (0);
                i++;
        }
        return (1);
}