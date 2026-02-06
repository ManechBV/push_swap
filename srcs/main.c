/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:18:18 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 23:53:53 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "libft.h"

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
	free_vars(vars);
	return (0);
}
