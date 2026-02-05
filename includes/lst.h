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
