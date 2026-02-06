/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:38:42 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 23:04:41 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"

static void	radix_sort(t_vars *vars, int mask)
{
	int	nb_loops;
	int	i;

	nb_loops = vars->len_a;
	i = 0;
	while (i < nb_loops)
	{
		if ((vars->stk_a->val & (1 << mask)) == 0)
			pb(vars);
		else
			ra(vars);
		i++;
	}
	while (vars->stk_b != NULL)
		pa(vars);
}

static int	ft_is_sorted(t_vars *vars)
{
	t_lst	*curr;

	curr = vars->stk_a;
	while (curr)
	{
		if (curr->prev)
		{
			if (curr->prev->val > curr->val)
				return (1);
		}
		curr = curr->next;
	}
	return (0);
}

static void	three_sort(t_vars *vars)
{
	t_lst	*lst[3];

	lst[0] = vars->stk_a;
	lst[1] = vars->stk_a->next;
	lst[2] = vars->stk_a->next->next;
	if (lst[0]->val > lst[1]->val)
	{
		if (lst[2]->val > lst[0]->val)
		{
			sa(vars);
			if (ft_is_sorted(vars) == 1)
				rra(vars);
		}
		else
		{
			if (lst[2]->val > lst[1]->val)
				ra(vars);
			else
				sa_rra(vars);
		}
	}
	else if (lst[0]->val < lst[2]->val)
		ra_sa_rra(vars);
	else
		rra(vars);
}

static void	five_sort(t_vars *vars)
{
	while (vars->len_a > 3)
		push_lowest(vars);
	if (ft_is_sorted(vars) == 1)
		three_sort(vars);
	pa(vars);
	pa(vars);
}

void	ft_choose_sort(t_vars *vars)
{
	int	mask;

	if (ft_is_sorted(vars) == 0)
		return ;
	if (vars->len_a == 2)
	{
		if (vars->stk_a->val > vars->stk_a->next->val)
			sa(vars);
	}
	else if (vars->len_a == 3)
		three_sort(vars);
	else if (vars->len_a <= 5)
		five_sort(vars);
	else
	{
		mask = 0;
		while (mask < 16 && ft_is_sorted(vars) == 1)
		{
			radix_sort(vars, mask);
			mask++;
		}
	}
}
