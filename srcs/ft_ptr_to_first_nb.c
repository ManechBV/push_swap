/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_first_nb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:46:32 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/13 20:53:41 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "libft.h"

char	*ft_ptr_to_first_nb(char *pchr)
{
	int	i[2];

	if (ft_strlen(pchr) > 2)
	{
		if (pchr[0] == '0' && pchr[1] == '\0')
			return (pchr);
		if (pchr[0] == '-' && pchr[1] == '0' && pchr[2] == '\0')
			return (&pchr[1]);
	}
	*i = 0;
	while ((pchr[*i] == '0' || pchr[*i] == '-' || pchr[*i] == '+') && pchr[*i])
		(*i)++;
	if (pchr[*i] == '\0')
		return (&pchr[*i - 1]);
	if (pchr[0] == '-' && *i > 0)
	{
		pchr[*i - 1] = '-';
		i[1] = -1;
		while (++(i[1]) < *i - 1)
			pchr[i[1]] = ' ';
		return (&pchr[*i - 1]);
	}
	while (pchr[*i] == ' ')
		(*i)++;
	return (&pchr[*i]);
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
