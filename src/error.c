#include <stdio.h>
#include <stdlib.h>
#include "../includes/swap.h"
#include "../libft/libft.h"

void    error(int i)
{
    if (i == 1)
        ft_putstr("error allocating memory\n"); // hier is al gemalloced
    if (i == 2) // hier is geen malloc
        ft_putstr("Usage: program_name int_value_1 int_value_2 etc\n");
    if (i == 3)
        ft_putstr("Usage: use one of the aloud commamnds\n");
    if (i == 4)
        ft_putstr("Usage: No duplicate numbers\n");
    exit(0);
}

void    free_all(t_swap *swap)
{
    t_data *walker;

    walker = (t_data*)malloc(sizeof(t_data));
    if (!swap)
        error(1);
    walker = swap->stack_a;
    while (swap->stack_a != NULL)
    {
        walker = swap->stack_a;
        swap->stack_a = walker->next;
        free (swap->stack_a);
    }
    while (swap->stack_b != NULL)
    {
        walker = swap->stack_b;
        swap->stack_b = walker->next;
        free (swap->stack_b);
    }
    free(swap->end_stack_a);
    free(swap->end_stack_b);
    free(walker);
    free(swap);
    exit(0);
}
