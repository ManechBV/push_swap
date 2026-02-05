/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:09:09 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 00:09:10 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_lst
{
	int				val;
	int				id;
	int				*len;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

// lst.c
t_lst			*new_lst(int val);
void			free_lst(t_lst *head);
void			push_lst(t_lst **head, int val);
void			append_lst(t_lst *head, int val);

#endif
