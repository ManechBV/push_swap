#ifndef VARS_H
# define VARS_H

# include "lst.h"

typedef struct s_vars
{
	t_lst	*stk_a;
	t_lst	*stk_b;
	int		len_a;
	int		len_b;
}	t_vars;

// vars.c
t_vars			*init_vars();
void			free_vars(t_vars *vars);

// swap.c
void			swap(t_lst **p_head);
void			sa(t_vars *vars);
void			sb(t_vars *vars);
void			ss(t_vars *vars);

// len.c
unsigned int	len_a(t_vars *vars);
unsigned int	len_b(t_vars *vars);

#endif
