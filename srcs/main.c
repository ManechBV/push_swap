/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:18:18 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/03 16:54:45 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

#include <stdio.h> //   AAAAA EEENNNNLLLLEEEVVVVVEEERRRRRR

int	main(int ac, char **av)
{
	t_vars	*vars;
	
	if (ac < 2)
		return (-1);
	vars = init_vars();
	if (!vars)	
		return (-1);
	ft_convert_argv(ac, av, vars->stk_a);
	printf("\nlen: %d\n", vars->len_a);
	sa(vars);

	t_lst	*curr = vars->stk_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->val);
		curr = curr->next;
	}

	free_vars(vars);
	return (0);
}
