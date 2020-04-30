#include "../includes/swap.h"
#include <stdlib.h>
#include "../libft/libft.h"

void    get_algo(t_swap *swap)
{
    if (swap->aca == 2)
        //swap->algo = 2;
        algo_two(swap, 'a');
    else if (swap->aca == 3)
        //swap->algo = 3;
        algo_three(swap, 'a');
    else if (swap->aca == 5)
        //swap->algo = 5;
        algo_five(swap, 'a');
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
        //free_all(swap);
        error(1);
    get_algo(swap);
    if (last_check(swap) == 1)
        //free_all(swap);
        error(1);
    while (end != 1)
    {
        ft_putstr("push_swap while loop\n");
        //choose_algo(swap);
        //here comes the mpv algortihme
        end = last_check(swap);
    }
    //free_all(swap);
}