#include "../includes/swap.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void    step_parser(t_swap *swap, char *str)
{
    int i;
    int j;
    int val;

    j = 0;
    i = 0;
    while (str[i] != '\0')
    {
        while (str[i] != ' ' && str[i] != '\0')
        {
            swap->step[j] = str[i];
            i++;
            j++;
        }
        val = check_step(swap, swap->step);
        if (val == 1)
        {
            steps_choose(swap);
            test_print_list(swap);
        }
        if (str[i] != '\0')
        {
            i++;
            j++;
        }
    }
}

void    ics_get_end_a(t_swap *swap)
{
    t_data  *walker;

    walker = (t_data*)malloc(sizeof(t_data));
    if (!walker)
        error(1);
    walker = swap->stack_a;
    while (walker->next != NULL)
        walker = walker->next;
    swap->end_stack_a = walker;
}

void    ics_get_end_b(t_swap *swap)
{
      t_data  *walker;

    walker = (t_data*)malloc(sizeof(t_data));
    if (!walker)
        error(1);
    walker = swap->stack_b;
    while (walker->next != NULL)
        walker = walker->next;
    swap->end_stack_b = walker;
}

t_data   *input_check_store(char **str, int ac)
{
    int hold;
    int j;
    t_data *temp;
    t_data *stack_a;

    j = 0;
    hold = 0;

    stack_a = NULL;
    while(j < (ac - 1))
    {
        hold = ft_atoi(str[j]);
        if ((!hold) || (hold > 2147483647) || (hold < -2147483648)) // deze doet het nog niet
            error(2);
        //check for doubles
        temp = make_list_value(hold);
        if (!temp)
            error(1); //hier kan er al gemalloced zijn 
        if (stack_a == NULL)
        {
            stack_a = (t_data*)malloc(sizeof(t_data));
            if (!stack_a)
                error(1);
            stack_a = temp;
        }
        else
            add_data_front(&stack_a, temp);
            //if it needs to be around i will make add_data_back
        j++;
    }
    return (stack_a);
}