/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <mabenois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:10:07 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 21:25:47 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"
#include "ft_printf.h"

void	swap(t_lst **p_head)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*third;
	
	first = *p_head;
	second = first->next;
	first->prev = second;
	third = NULL;
	if (second->next)
	{
		third = second->next;
		first->next = third;
	}
	else
		first->next = NULL;
	second->prev = NULL;
	second->next = first;
	if (third)
		third->prev = first;
	*p_head = second;
}

void	sa(t_vars *vars)
{
	if (vars->len_a > 1)
	{
		swap(&vars->stk_a);
		ft_printf("sa\n");
	}
}

void	sb(t_vars *vars)
{
	if (vars->len_b > 1)
	{
		swap(&vars->stk_b);
		ft_printf("sb\n");
	}
}

void	ss(t_vars *vars)
{
	sa(vars);
	sb(vars);
}

void			sa_rra(t_vars *vars)
{
	sa(vars);
	rra(vars);
}
