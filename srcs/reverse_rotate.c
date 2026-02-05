/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:44:49 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/05 19:58:25 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"

#include <stdio.h>
void	rrotate(t_lst **p_head)
{
	t_lst	*first;
	t_lst	*second_last;
	t_lst	*last;

	first = *p_head;
	last = first;
	while (last->next != NULL)
		last = last->next;
	second_last = last->prev;
	last->prev = NULL;
	last->next = first;
	second_last->next = NULL;
	first->prev = last;
	*p_head = last;
}

void	rra(t_vars *vars)
{
	if (vars->len_a > 2)
		rrotate(&vars->stk_a);
	else if (vars->len_a == 2)
		sa(vars);
}

void	rrb(t_vars *vars)
{
	if (vars->len_b > 2)
		rrotate(&vars->stk_b);
	else if (vars->len_b == 2)
		sb(vars);
}

void	rrr(t_vars *vars)
{
	rra(vars);
	rrb(vars);
}

