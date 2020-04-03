#include "includes/swap.h"
#include "libft/libft.h"
//#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)

{
    t_data      *stack_a;

    if (argc != 1)
    {
        stack_a = input_check_store(&argv[1], argc);
        //ft_putstr("heart_between tests\n");
        if (argv[0][2] == 'c')
        {
            heart_entry(&stack_a, argc);
            free(stack_a);
            exit(0);
        }
        if (argv[0][2] == 'p')
        {
            ft_putstr("start push_swap\n");
            //heart_push(&stack_a, argc);
        }
    }
    else
        error(2);
    return (0);
}