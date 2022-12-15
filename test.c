#include "monty.h"

int main()
{
        char *line = "        pall     ";

        printf("%d\n", check_empty_line(line, DELIMITERS));
}