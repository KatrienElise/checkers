#include "../includes/swap.h"
#include <stdlib.h>
#include "../libft/libft.h"

void    choose_algo(t_swap *swap)
{
    if (swap->algo == 2)
        algo_two(swap);
    else if (swap->aca = 3)
        algo_three(swap);
    else if (swap->aca = 5)
        algo_five(swap);
    else
        algo_mpv(swap);
}