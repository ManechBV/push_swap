/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:08:18 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/10 19:16:38 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "libft.h"

static int	occ_val_lst(t_vars *vars, int n)
{
	t_lst	*curr;
	int		occ;

	occ = 0;
	curr = vars->stk_a;
	while (curr)
	{
		if (curr->val == n)
			occ++;
		curr = curr->next;
	}
	return (occ);
}

static int	add_split_to_lst(char **pchr, t_vars *vars)
{
	int		i;
	long	res;

	i = 0;
	while (pchr[i] != NULL)
	{
		res = ft_atoi(pchr[i]);
		if (res > 2147483647 || res < -2147483648)
			return (-1);
		if (!vars->stk_a)
		{
			vars->stk_a = new_lst((int) res);
			if (!vars->stk_a)
				return (-1);
		}
		else
			append_lst(vars->stk_a, (int) res);
		if (occ_val_lst(vars, (int) res) > 1)
			return (-1);
		vars->len_a++;
		i++;
	}
	return (0);
}

static void	free_split(char **split)
{
	int		j;

	j = 0;
	while (split[j] != NULL)
	{
		free(split[j]);
		j++;
	}
	free(split);
}

static int	only_digit(char **split)
{
	int		i;
	int		j;
	char	c;
	char	*pchr;

	i = 0;
	while (split[i])
	{
		pchr = ft_ptr_to_first_nb(split[i]);
		if (ft_strlen(pchr) > 11)
			return (1);
		j = 0;
		while (split[i][j])
		{
			c = split[i][j];
			if (ft_isdigit(c) == 0 && c != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_convert_argv(int argc, char **argv, t_vars *vars)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		if (only_digit(split) == 1)
		{
			free_split(split);
			return (-1);
		}
		if (add_split_to_lst(split, vars) == -1)
		{
			free_split(split);
			return (-1);
		}
		free_split(split);
		i++;
	}
	return (0);
}
