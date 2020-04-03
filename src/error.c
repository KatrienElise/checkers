#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void    error(int i)
{
    if (i == 1)
        ft_putstr("error allocating memory\n"); // hier is al gemalloced
    if (i == 2) // hier is geen malloc
        ft_putstr("Usage: program_name int_value_1 int_value_2 etc\n");
    if (i == 3)
        ft_putstr("Usage: use one of the aloud commamnds\n");
    exit(0);
}
