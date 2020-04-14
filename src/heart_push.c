#include "../includes/swap.h"
#include <stdlib.h>
#include "../libft/libft.h"

void    get_algo(t_swap *sap)
{
    if (swap->aca = 2)
        swap->algo = 2;
    else if (swap->aca = 3)
        swap->algo = 3;
    else if (swap->aca = 5)
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
    swap->n = swap->aca / 2;
    swap->stack_a = *stack_a;
    ics_get_end_a(swap);
    test_print_list(swap);
    if (last_check(swap) == 1)
        free_all(swap);
    while (end != 1)
    {
        get_algo(swap);
        choose_algo(swap);
        end = last_check(swap);
    }
    free_all(swap);
}