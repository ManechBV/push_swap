/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_first_nb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:46:32 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/13 15:55:07 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

char	*ft_ptr_to_first_nb(char *pchr)
{
	while (*pchr == '0' && *pchr)
		pchr++;
	return (pchr);
}

size_t	ft_longlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len = 1;
		n = n * -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
