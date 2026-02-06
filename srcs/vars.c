/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:08:28 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 23:53:04 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"

t_vars	*init_vars(void)
{
	t_vars	*new;

	new = malloc(sizeof(t_vars));
	if (!new)
		return (NULL);
	new->stk_a = NULL;
	new->stk_b = NULL;
	new->len_a = 0;
	new->len_b = 0;
	return (new);
}

void	free_vars(t_vars *vars)
{
	free_lst(vars->stk_a);
	free_lst(vars->stk_b);
	free(vars);
}
