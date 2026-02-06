/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:18:18 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 19:00:22 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "libft.h"


	/*
#include <stdio.h> //   AAAAA EEENNNNLLLLEEEVVVVVEEERRRRRR
static void	_debug_show_stacks(t_vars *vars)
{
	int	stk_a[200];
	int	stk_b[200];

	for (int x = 0; x < 200; x++)
	{
		stk_a[x] = 0;
		stk_b[x] = 0;
	}
	int greater_i = 0;
	int i = 0;
	t_lst	*curr = vars->stk_a;
	while (curr != NULL)
	{
		stk_a[i] = curr->val;
		curr = curr->next;
		i++;
	}
	greater_i = i;

	i = 0;
	curr = vars->stk_b;
	while (curr != NULL)
	{
		stk_b[i] = curr->val;
		curr = curr->next;
		i++;
	}
	if (i > greater_i)
		greater_i = i;
	i = 0;
	printf("\n A \t B\n");
	while (i < greater_i)
	{
		if (i < vars->len_a && i < vars->len_b)
			printf("| %d \t| %d\n", stk_a[i], stk_b[i]);
		else if (i < vars->len_a && i >= vars->len_b)
			printf("| %d \t|  \n", stk_a[i]);
		else if (i >= vars->len_a && i < vars->len_b)
			printf("|   \t| %d\n", stk_b[i]);
		else
			printf("|   \t|  \n");
		i++;
	}
	printf("-- \t --\nl:%d \t l:%d\n", vars->len_a, vars->len_b);
}
*/


int	main(int ac, char **av)
{
	t_vars	*vars;
	
	if (ac < 2)
		return (-1);
	vars = init_vars();
	if (!vars)	
		return (-1);
	if (ft_convert_argv(ac, av, vars) == -1)
		ft_putendl_fd("Error", 2);
	else
		ft_choose_sort(vars);
	/*

	_debug_show_stacks(vars);
	sa(vars);
	_debug_show_stacks(vars);

	pb(vars);
	pb(vars);
	pb(vars);
	_debug_show_stacks(vars);

	ss(vars);
	_debug_show_stacks(vars);

	rr(vars);
	_debug_show_stacks(vars);

	rrr(vars);
	_debug_show_stacks(vars);
	*/
	free_vars(vars);
	return (0);
}
