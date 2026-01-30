#include "lst.h"
#include "libft.h"

int	ft_convert_argv(int argc, char **argv, t_lst *lst)
{
	int	i;

	if (!lst)
		return (-1);
	i = 1;
	lst->val = ft_atoi(argv[i]);
	while (++i < argc)
		append_lst(lst, ft_atoi(argv[i]));
	return (0);
}
