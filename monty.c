#include "monty.h"

int main(int ac, char *av[])
{
    FILE *file;
    
    if (ac != 2)
    {
        write(2, "USAGE: monty file\n", 18);
        exit(1);
    }
}