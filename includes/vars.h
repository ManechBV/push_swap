#ifndef VARS_H
# define VARS_H

# include "lst.h"

typedef struct s_vars
{
	t_lst	*stk_a;
	t_lst	*stk_b;
}	t_vars;

// vars.c
t_vars	*init_vars();

#endif
