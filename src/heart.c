#include "../includes/swap.h"
#include <stdlib.h>
#include "../libft/libft.h"

void    ini_swap_zero(t_swap *swap)
{
    swap->stack_a = NULL;
    swap->stack_b = NULL;
    swap->end_stack_a = NULL;
    swap->end_stack_b = NULL;
    swap->aca = 0;
    swap->acb = 0;
    swap->n = swap->aca / 2;
    swap->algo = 0;
    swap->step = NULL;
}

void    heart_entry(t_data **stack_a, int ac)
{
    t_swap  *swap;
    int     end;
    int     val;

    val = 1;
    end = 0;
    swap = (t_swap*)malloc(sizeof(t_swap));
    if (!swap)
        error(1);
    ini_swap_zero(swap);
    swap->aca = ac - 1;
    swap->stack_a = *stack_a;
    ics_get_end_a(swap);
    test_print_list(swap);
    if (last_check(swap) == 1)
        free_all(swap); // moet alles gefreed worden met speciala free functie
    while (end != 1)
    {
        ft_putstr("before gnl\n");
        get_next_line(0, &swap->step);
        ft_putstr("after gnl\n");
        step_parser(swap, swap->step);
        end = last_check(swap);
    }
    free_all(swap);
    /*
    free(swap->end_stack_a);
    free(swap->end_stack_b);
    free(swap->stack_b);
    free(swap->stack_a);
    */
}
