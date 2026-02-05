/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:38:42 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/05 21:48:10 by mabenois         ###   ########.fr       */
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
	{
		rrb(vars);
		pa(vars);
		ra(vars);
	}
}

static int	ft_is_sorted(t_vars *vars)
{
	t_lst	*curr;

	if (vars->stk_b)
		return (1);
	curr = vars->stk_a;
	while (curr)
	{
		if (curr->prev)
		{
			if (curr->prev->val < curr->val)
				return (1);
		}
		curr = curr->next;
	}
	return (0);
}

void	ft_radix(t_vars *vars)
{
	int	i;
	int	i_max;
	int	mask;

	mask = 0;
	while (mask < 16 && ft_is_sorted(vars) == 1)
	{
		radix_sort(vars, mask);
		mask++;
	}
	i_max = vars->len_a;
	i = 0;
	while (i < i_max)
	{
		rra(vars);
		pb(vars);
		i++;
	}
	i = 0;
	while (i < i_max)
	{
		pa(vars);
		i++;
	}
}
