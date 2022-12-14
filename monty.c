#include "monty.h"

int main(int ac, char *av[])
{
        char *error;
        int fd, fstat, error_size;
        FILE *file;

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
}