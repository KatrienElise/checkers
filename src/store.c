#include "../includes/swap.h"
#include "../libft/libft.h"
#include <stdio.h>
t_data  *create_b(int ac)
{
    int     i;
    t_data  *stack_b;
    t_data  *temp;

    i = 1;
    stack_b = NULL;
    while (i < ac)
    {
        temp = make_list_value(0);
        if (!temp)
            error(1); //hier kan er al gemalloced zijn 
        //ft_putstr("inside make stack b\n");
        if (stack_b == NULL)
        {
           // ft_putstr("indise begin\n");
            stack_b = (t_data*)malloc(sizeof(t_data));
            if (!stack_b)
                error(1);
            stack_b = temp;
        }
        else
            add_data_front(&stack_b, temp);
        i++;
    }
    return (stack_b);
}

void    add_prev(t_data **newy, t_data *stack_a)
{
    stack_a->prev = *newy;
}

void    add_data_front(t_data **stack_a, t_data *newy)
{
    newy->next = *stack_a;
    add_prev(&newy, *stack_a);
    *stack_a = newy;
}

int    check_step(t_swap *swap, char *str)
{
    ft_putstr("in store stept\n");
    // check for invalid comment with pb and pa
    if ((swap->aca == 0 && str[1] == 'a' && str[0] != 'p') || \
        (str[0] == 'p' && str[1] == 'b' && swap->aca == 0))
    {
        ft_putstr("no more value in stack a\n");
        return (0);
    }
    if ((swap->acb == 0 && str[1] == 'b' && str[0] != 'p') || \
        (str[0] == 'p' && str[1] == 'a' && swap->acb == 0))
    {
        ft_putstr("no more value in stack b\n");
        return (0);
    }
    else
        return (1);
}

t_data  *make_list_value(int hold)
{
    t_data      *stack;

    stack = (t_data*)malloc(sizeof(t_data));
    if (!stack)
        error(1);
    else
    {
        stack->value = hold; // in stack_b is it 0?
        stack->prev = NULL;
        stack->next = NULL;
    }
    return (stack);
}