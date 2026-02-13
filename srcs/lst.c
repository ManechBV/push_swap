/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:08:36 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/13 20:25:03 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

t_lst	*new_lst(int val)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->val = val;
	new->id = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	free_lst(t_lst *head)
{
	t_lst	*curr;

	if (!head)
		return ;
	curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		if (curr->prev)
			free(curr->prev);
	}
	free(curr);
}

void	push_lst(t_lst **p_head, int val)
{
	t_lst	*node;

	node = new_lst(val);
	if (!node)
		return ;
	node->next = *p_head;
	(*p_head)->prev = node;
	*p_head = node;
}

void	append_lst(t_lst *head, int val)
{
	t_lst	*node;
	t_lst	*curr;

	node = new_lst(val);
	if (!node)
		return ;
	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	node->prev = curr;
	curr->next = node;
}
