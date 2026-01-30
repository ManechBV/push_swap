#include <stdlib.h>
#include "vars.h"

t_vars	*init_vars()
{
	t_vars	*new;

	new = malloc(sizeof(t_vars));
	if (!new)
		return (NULL);
	new->stk_a = new_lst(0);
	new->stk_b = new_lst(0);
	return (new);
}
