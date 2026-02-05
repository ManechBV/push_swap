/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:38:42 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/05 21:06:52 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"

static void	radix_sort(t_vars *vars)
{
	int	nb_loops;
	int	i;
	int	mask;

	mask = 0;
	while (mask < 16)
	{
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
		mask++;
	}
}

void	ft_radix(t_vars *vars)
{
	int	i;
	int	i_max;

	radix_sort(vars);
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
