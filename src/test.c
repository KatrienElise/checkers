#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/swap.h"
// print hij het verkeerd of is de stack verkeerd
void    usage(void)
{
    printf("sa = swaps top 2\npa = switch top b to a\n");
    printf("rra = rise, bottom to top\nra = drown, top to bottom\n");
}

void    test_print_list(t_swap *swap)
{
    t_data  *walker_a;
    t_data  *walker_b;
    int     xa;
    int     xb;

    xa = 1;
    xb = 1;
    walker_a = swap->end_stack_a;
    walker_b = swap->end_stack_b;
    ft_putstr("stack_a          stack_b\n");
    if (walker_a != NULL)
         ft_putnbr(walker_a->value);
    ft_putstr("                ");
    if (walker_b != NULL)
        ft_putnbr(walker_b->value);
    ft_putchar('\n');
    while (swap->aca > xa || swap->acb > xb)
    {
        if (xa == swap->aca || swap->aca == 0)
            ft_putchar(' ');
        else
        {
            walker_a = walker_a->prev;
            ft_putnbr(walker_a->value);
            xa++;
        }
        ft_putstr("                 ");
        if (xb == swap->acb || swap->acb == 0)
            ft_putchar(' ');
        else
        {
            walker_b = walker_b->prev;
            ft_putnbr(walker_b->value);
            xb++;
        }
        ft_putchar('\n');
    }
    ft_putchar('\n');
}

int    last_check(t_swap *swap)
{
    t_data  *walker;
    t_data  *walker1;
    int     a;

    if (swap->stack_b != NULL)
    {
        ft_putstr("ko\n");
        return (0);
    }
    a = 0;
    walker = swap->end_stack_a;
    walker1 = swap->end_stack_a;
    walker1 = walker1->prev;
    while(walker->prev != NULL && a == 0)
    {
        if (walker->value < walker1->value)
        {
            walker = walker->prev;
            walker1 = walker1->prev;
        }
        else
            return (0);
    }
    ft_putstr("OK\n");
    return (1);
}