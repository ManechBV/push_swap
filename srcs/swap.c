/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <mabenois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:10:07 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/03 16:43:10 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"

void	swap(t_lst **p_head)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*third;

	if (len_lst(*p_head) < 3)
		return ;
	first = *p_head;
	second = first->next;
	third = second->next;
	first->prev = second;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	third->prev = first;
	*p_head = second;
}

void	sa(t_vars *vars)
{
	swap(&vars->stk_a);
}

void	sb(t_vars *vars)
{
	swap(&vars->stk_b);
}

void	ss(t_vars *vars)
{
	sa(vars);
	sb(vars);
}
