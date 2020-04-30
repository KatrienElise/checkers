#include "../includes/swap.h"
#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>

/*void    choose_algo(t_swap *swap)
{
    if (swap->algo == 2)
        algo_two(swap);
    else if (swap->algo == 3)
        algo_three(swap);
    else if (swap->algo == 5)
        algo_five(swap);
    else
        algo_mpv(swap);
}
*/
void    algo_two(t_swap *swap, char stack)
{
    if (swap->end_stack_a > swap->stack_a && stack == 'a')
    {
        swap->step = "sa";
        swaps(swap);
    }
    if (swap->end_stack_b > swap->stack_b && stack == 'b')
    {
        swap->step = "sb";
        swaps(swap);
    }
    ft_putstr(swap->step);
    ft_putstr(":\n");
    test_print_list(swap);
}

void    algo_three(t_swap *swap, char stack)
{
     t_data  *walker;
    int     end;

    /* is it the three from stack a or b ? Also does it need 
    to keep track of which three, lets say three top ones from
    stack_b, after they get pushed to a */
    walker = swap->end_stack_a->prev;
    end = last_check(swap);
    ft_putstr("dit is end: ");
    ft_putchar(end);
    if (end != 1)
    {
        if (stack == 'a')
        {
            if ((swap->end_stack_a < swap->stack_a) && \
            (swap->end_stack_a < walker))
            {
                swap->step = "pb";
                steps_choose(swap);
                algo_two(swap, 'a');
                swap->step = "pa";
                steps_choose(swap);
            }
            else if (swap->end_stack_a > swap->stack_a && \
            swap->end_stack_a > walker)
            {
                swap->step = "ra";
                steps_choose(swap);
            }
            else if (swap->end_stack_a < swap->stack_a && \
            swap->end_stack_a > walker)
            {
                swap->step = "sa";
                steps_choose(swap);
            }
        }
        end = last_check(swap);
        algo_three(swap, 'a');
    }
    //swap = NULL;
    ft_putstr("algo THREE\n");
}

void    algo_five(t_swap *swap, char stack)
{
    swap = NULL;
    stack = 'b';
    ft_putstr("algo five\n");
}

void    algo_mpv(t_swap *swap, char stack)
{
    swap = NULL;
    stack = 'b';
    ft_putstr("algo mpv\n");
}