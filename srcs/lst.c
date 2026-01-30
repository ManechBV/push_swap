#include <stdlib.h>
#include "lst.h"

t_lst	*new_lst(int val)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->val = val;
	new->id = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push_lst(t_lst *head, int val)
{
	t_lst	*node;

	node = new_lst(val);
	if (!node)
		return ;
	node->next = head;
	head->prev = node;
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
