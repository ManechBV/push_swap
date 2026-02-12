/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:18:18 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/12 02:45:29 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "libft.h"

static int	check_empty_argv(int ac, char **av)
{
	int	i;
	int	j;
	int	digit_occ;

	i = 1;
	while (i < ac)
	{
		digit_occ = 0;
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) != 0)
				digit_occ++;
			j++;
		}
		if (digit_occ == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac < 2)
		return (-1);
	vars = init_vars();
	if (!vars)
		return (-1);
	if (check_empty_argv(ac, av) == -1)
		ft_putendl_fd("Error", 2);
	else if (ft_convert_argv(ac, av, vars) == -1)
		ft_putendl_fd("Error", 2);
	else
		ft_choose_sort(vars);
	free_vars(vars);
	return (0);
}
