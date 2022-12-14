#include "monty.h"

int main(int ac, char *av[])
{
        char *line;
        int fd, fstat, error_size;
        FILE *file;
	char **line_token;

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
        
        while (fgets(line, sizeof(line), file))
        {
            printf("%s", line);
        }
}
