/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:26:04 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/13 20:38:20 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"

void	ft_normalize(t_vars *vars)
{
	t_lst	*curr;
	t_lst	*lowest;
	int		i;

	i = 0;
	while (i < vars->len_a)
	{
		curr = vars->stk_a;
		lowest = NULL;
		while (curr)
		{
			if (!lowest || curr->val < lowest->val)
				if (curr->id == -1)
					lowest = curr;
			curr = curr->next;
		}
		lowest->id = i;
		i++;
	}
}
