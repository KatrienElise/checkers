#ifndef SWAP_H
# define SWAP_H

//# include <stdlib.h>
//# include <stdio.h>
//# include <unistd.h>
//# include "../libft/libft.h"

typedef struct      s_data
{
    struct s_data   *prev;
    int             value;
    struct s_data   *next;
    
}                   t_data;

typedef  struct     s_swap
{
    t_data         *stack_a;
    t_data         *stack_b;
    t_data         *end_stack_a;
    t_data         *end_stack_b;
    int             aca;
    int             count;
    int             acb;
    int             algo;
    char            *step;       
}                   t_swap;

t_data   *input_check_store(char **str, int ac);
void    step_parser(t_swap *swap, char *str);
void    ics_get_end_a(t_swap *swap);
void    ics_get_end_b(t_swap *swap);

int     check_step(t_swap *swap, char *str);
t_data  *create_b(int ac);
t_data   *make_list_value(int hold);
void    add_prev(t_data **newy, t_data *stack_a);
void    add_data_front(t_data **stack_a, t_data *newy);

void    error(int i);

void    test_print_list(t_swap *swap);
int    last_check(t_swap *swap);
void    usage(void);

void    ini_swap_zero(t_swap *swap);
void    heart_entry(t_data **stack_a, int ac);

void    steps_choose(t_swap *swap);
void    swaps(t_swap *swap);
void    switch_top(t_swap *swap);
void    drown(t_swap *swap);
void    rise(t_swap *swap);

void    heart_push(t_data **stack_a, int ac);
void    choose_algo(t_swap *swap);
#endif