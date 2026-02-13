/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:09:14 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/13 15:53:51 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include <stdlib.h>
# include "lst.h"

typedef struct s_vars
{
	t_lst	*stk_a;
	t_lst	*stk_b;
	int		len_a;
	int		len_b;
}	t_vars;

// vars.c
t_vars			*init_vars(void);
void			free_vars(t_vars *vars);

// parsing.c
int				ft_convert_argv(int argc, char **argv, t_vars *vars);

// swap.c
void			swap(t_lst **p_head);
void			sa(t_vars *vars);
void			sb(t_vars *vars);
void			ss(t_vars *vars);
void			sa_rra(t_vars *vars);

// push.c
void			pa(t_vars *vars);
void			pb(t_vars *vars);

// rotate.c
void			rotate(t_lst **p_head);
void			ra(t_vars *vars);
void			rb(t_vars *vars);
void			rr(t_vars *vars);
void			ra_sa_rra(t_vars *vars);

// reverse_rotate.c
void			rrotate(t_lst **p_head);
void			rra(t_vars *vars);
void			rrb(t_vars *vars);
void			rrr(t_vars *vars);

// ft_radix.c
void			ft_choose_sort(t_vars *vars);

// push_lowest.c
void			push_lowest(t_vars *vars);

// ft_ptr_to_first_nb.c
char			*ft_ptr_to_first_nb(char *pchr);
size_t			ft_longlen(long n);

#endif
