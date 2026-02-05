#include <stdlib.h>
#include "vars.h"

void	pa(t_vars *vars)
{
	t_lst	*tmp;

	if (vars->len_b == 0)
		return ;
	tmp = vars->stk_b->next;
	vars->stk_b->next = vars->stk_a;
	vars->stk_a->prev = vars->stk_b;
	tmp->prev = NULL;
	vars->stk_a = vars->stk_a->prev;
	vars->stk_b = tmp;
	vars->len_a++;
	vars->len_b--;
}

void	pb(t_vars *vars)
{
	t_lst	*tmp;

	if (vars->len_a == 0)
		return ;
	tmp = vars->stk_a->next;
	vars->stk_a->next = vars->stk_b;
	vars->stk_b->prev = vars->stk_a;
	tmp->prev = NULL;
	vars->stk_b = vars->stk_b->prev;
	vars->stk_a = tmp;
	vars->len_b++;
	vars->len_a--;
}
