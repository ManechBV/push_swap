/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lowest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:32:02 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 22:28:56 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"

void	push_lowest(t_vars *vars)
{
	int		i[4];
	t_lst	*tmp;

	i[0] = 0;
	tmp = vars->stk_a;
	i[2] = vars->stk_a->val;
	while (tmp)
	{
		if (tmp->val < i[2])
		{
			i[2] = tmp->val;
			i[1] = i[0];
		}
		i[0]++;
		tmp = tmp->next;
	}
	i[0] = i[1];
	i[3] = vars->len_a - 4;
	if (i[1] < vars->len_a / 2 + i[3] || i[1] == 2)
		while (i[0]-- > 0)
			ra(vars);
	else
		while (i[0]++ < vars->len_a)	
			rra(vars);
	pb(vars);
}
