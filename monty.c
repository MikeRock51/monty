#include "monty.h"

int main(int ac, char *av[])
{
        char *line = NULL, **line_token;
        int fd;
        FILE *file;
        size_t line_size = 0, line_number = 1;

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
            line_token = tokenize(line);
            int i = 0;
            // printf("line %lu\n", line_number);
            while(line_token[i])
            {
                printf("%s\n", line_token[i]);
                i++;
            }
            line_number++;
        }

        // }
        // int i = 0;
        // char s[50] = "      push    6        ";
        // line_token = tokenize(s);
        // while(line_token[i])
        // {
        //         printf("%s\n", line_token[i]);
        //         i++;
        // }
}
