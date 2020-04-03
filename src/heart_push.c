#include "../includes/swap.h"
#include <stdlib.h>
#include "../libft/libft.h"

void    choose_algo(t_swap *swap)
{
    if (swap->count = 1)
        swap->algo = 1;
    else if (swap->count = 2)
        swap->algo = 2;
    else if (swap->count = 3)
        swap->algo = 3;
    else if (swap->count = 5)
        swap->algo = 5;
    else
        swap->algo = 4;
}

void    heart_push(t_data **stack_a, int ac)
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
    swap->count = swap->aca;
    swap->stack_a = *stack_a;
    ics_get_end_a(swap);
    test_print_list(swap);
    while (end != 1)
    {
        choose_algo(swap);
        end = last_check(swap);
    }
}