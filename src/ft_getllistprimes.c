/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getllistprimes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:55:15 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/28 17:05:25 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/gnp_service.h"
#include "../libft/libft.h"
#include <stdlib.h>

static void	*crtint(unsigned long maxnum)
{
	unsigned long	*tmp;

	tmp = malloc(sizeof(unsigned long));
	*tmp = maxnum;
	return ((void *)tmp);
}

t_llist	*ft_getllistprimes(t_uchar *mrkprm, t_ulong maxnum, t_ulong minnum)
{
	t_uint	bit;
	t_ulong	i;
	t_llist	*primenums;

	if (!mrkprm)
		return (NULL);
	i = 0;
	primenums = NULL;
	while (i * FT_BIT_MAX + minnum <= maxnum)
	{
		bit = 0;
		while (bit < FT_BIT_MAX)
		{
			if (i * FT_BIT_MAX + bit + minnum > maxnum)
				break ;
			if (getbit(&(mrkprm[i]), bit))
				llistadd_back(&primenums, llistnewnode(
						crtint(i * FT_BIT_MAX + bit + minnum)));
			++bit;
		}
		++i;
	}
	return (primenums);
}
