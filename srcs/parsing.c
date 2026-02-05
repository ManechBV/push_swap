#include "vars.h"
#include "libft.h"

int	ft_convert_argv(int argc, char **argv, t_vars *vars)
{
	int		i;
	t_lst	*lst;

	lst = vars->stk_a;
	if (!lst)
		return (-1);
	i = 1;
	lst->val = ft_atoi(argv[i]);
	while (++i < argc)
		append_lst(lst, ft_atoi(argv[i]));
	vars->len_a = i - 1;
	return (0);
}
