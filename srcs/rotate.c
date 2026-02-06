/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:45:57 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 20:52:57 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"
#include "ft_printf.h"

void	rotate(t_lst **p_head)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*last;

	first = *p_head;
	second = first->next;
	last = second;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	second->prev = NULL;
	*p_head = second;
}

void	ra(t_vars *vars)
{
	if (vars->len_a > 2)
	{
		rotate(&vars->stk_a);
		ft_printf("ra\n");
	}
	else if (vars->len_a == 2)
		sa(vars);
}

void	rb(t_vars *vars)
{
	if (vars->len_b > 2)
	{
		rotate(&vars->stk_b);
		ft_printf("rb\n");
	}
	else if (vars->len_b == 2)
		sb(vars);
}

void	rr(t_vars *vars)
{
	ra(vars);
	rb(vars);
}

void	ra_sa_rra(t_vars *vars)
{
	ra(vars);
	sa(vars);
	rra(vars);
}
