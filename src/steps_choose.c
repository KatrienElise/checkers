#include "../includes/swap.h"
#include "../libft/libft.h"

void    steps_choose(t_swap *swap)
{
    if (swap->step[0] == 's')
        swaps(swap);
    else if (swap->step[0] == 'p')
        switch_top(swap);
    else if (swap->step[0] == 'u')
        usage();
    else
    {
        if (swap->step[1] == 'r' && (swap->step[2] == 'a' || swap->step[2] == 'b'))
            rise(swap);
        else
            drown(swap);
    }
}

void    swaps(t_swap *swap)
{
    t_data  *walker;
    int      keep;

    if (swap->step[1] == 'a' || swap->step[1] == 's')
    {
        walker = swap->end_stack_a;
        walker = walker->prev;
        keep = walker->value;
        walker->value = swap->end_stack_a->value;
        swap->end_stack_a->value = keep;

    }
    if (swap->step[1] == 'b' || swap->step[1] == 's')
    {
        walker = swap->end_stack_b;
        walker = swap->end_stack_b;
        walker = walker->prev;
        keep = walker->value;
        walker->value = swap->end_stack_b->value;
        swap->end_stack_b->value = keep;
    }
}

void    switch_top(t_swap *swap)
{
    t_data  *walker;

    if (swap->step[1] == 'a')
    { 
        if (swap->aca == 0)
        { 
            swap->end_stack_a = make_list_value(0);
            swap->stack_a = swap->end_stack_a;
            swap->stack_a->value = swap->end_stack_b->value;
            walker = swap->end_stack_b;
            walker = walker->prev;
            free(swap->end_stack_b);
            swap->end_stack_b = walker;
            swap->end_stack_b->next = NULL;
            swap->acb = swap->acb - 1;
            swap->aca = swap->aca + 1;;
        }
        walker = swap->end_stack_b;
        walker = walker->prev;
        swap->end_stack_a->next = swap->end_stack_b;
        swap->end_stack_b->prev = swap->end_stack_a;
        swap->end_stack_a = swap->end_stack_b;
        if (swap->acb == 1)
        {
            swap->end_stack_b = NULL;
            swap->stack_b = NULL;
        }
        else
        {
            walker->next = NULL;
            swap->end_stack_b = walker;

        }
        swap->aca = swap->aca + 1;
        swap->acb = swap->acb - 1;
    }
    if (swap->step[1] == 'b')
    {
        if (swap->acb == 0)
        { 
            swap->end_stack_b = make_list_value(0);
            swap->stack_b = swap->end_stack_b;
            swap->stack_b->value = swap->end_stack_a->value;
            walker = swap->end_stack_a;
            walker = walker->prev;
            free(swap->end_stack_a);
            swap->end_stack_a = walker;
            swap->end_stack_a->next = NULL;
            swap->aca = swap->aca - 1;
            swap->acb = swap->acb + 1;;
        }
        else
        {
            walker = swap->end_stack_a;
            swap->end_stack_b->next = swap->end_stack_a;
            walker = walker->prev;
            swap->end_stack_a->prev = swap->end_stack_b;
            swap->end_stack_b = swap->end_stack_a;
            if (swap->aca == 1)
            {
                swap->stack_a = NULL;
                swap->end_stack_a = NULL;
            }
            else
            {
                walker->next = NULL;
                swap->end_stack_a = walker;
            }
            swap->aca = swap->aca - 1;
            swap->acb = swap->acb + 1;
        }
    }
}
void    drown(t_swap *swap)
{
    t_data  *walker;
    
    if (swap->step[1] == 'a' || swap->step[1] == 'r')
    {
        walker = swap->end_stack_a;
        walker = walker->prev;
        swap->stack_a->prev = swap->end_stack_a;
        swap->end_stack_a->next = swap->stack_a;
        swap->end_stack_a = walker;
        swap->end_stack_a->next = NULL;
        swap->stack_a = swap->stack_a->prev;
        swap->stack_a->prev = NULL;
    }
    if (swap->step[1] == 'b' || swap->step[1] == 'r')
    {
        walker = swap->end_stack_b;
        walker = walker->prev;
        swap->stack_b->prev = swap->end_stack_b;
        swap->end_stack_b->next = swap->stack_b;
        swap->end_stack_b = walker;
        swap->end_stack_b->next = NULL;
        swap->stack_b = swap->stack_b->prev;
        swap->stack_b->prev = NULL;
    }
}

void    rise(t_swap *swap)
{
    t_data  *walker;

    if (swap->step[2] == 'a' || swap->step[2] == 'r')
    {
        walker = swap->stack_a;
        walker = walker->next;
        walker->prev = NULL;
        swap->end_stack_a->next = swap->stack_a;
        swap->stack_a->prev = swap->end_stack_a;
        swap->stack_a->next = NULL;
        swap->end_stack_a = swap->stack_a;
        swap->stack_a = walker;
    }
    if (swap->step[2] == 'b' || swap->step[2] == 'r')
    {
        walker = swap->stack_b;
        walker = walker->next;
        walker->prev = NULL;
        swap->end_stack_b->next = swap->stack_b;
        swap->stack_b->prev = swap->end_stack_b;
        swap->stack_b->next = NULL;
        swap->end_stack_b = swap->stack_b;
        swap->stack_b = walker;
    }
}
