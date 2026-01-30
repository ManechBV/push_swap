#ifndef LST_H
# define LST_H

typedef struct s_lst
{
	int				val;
	int				id;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

// lst.c
t_lst	*new_lst(int val);
void	push_lst(t_lst *head, int val);
void	append_lst(t_lst *head, int val);

// parsing.c
int		ft_convert_argv(int argc, char **argv, t_lst *lst);

#endif
