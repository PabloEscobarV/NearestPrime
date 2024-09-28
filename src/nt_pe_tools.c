/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_pe_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:58:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 22:10:09 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/gnp_service.h"
#include "../libft/libft.h"
#include "../ft_pow/hdrs/ft_pow.h"
#include <stdlib.h>

t_ulong	getelemprimearrsizze(t_ulong maxnum)
{
	t_ulong	tmp;

	if (maxnum / FT_BIT_MAX <= GNP_MAXARRSIZE)
		return (maxnum);
	tmp = (t_ulong)ft_sqrt(maxnum);
	if (tmp / FT_BIT_MAX <= GNP_MAXARRSIZE)
		return (tmp);
	return (GNP_MAXARRSIZE);
}

t_ulong	getprime(t_ulong maxnum, t_uchar *primearr)
{
	while (maxnum >= 0)
	{
		if (primearr[maxnum])
			break ;
		--maxnum;
	}
	free(primearr);
	return (maxnum);
}

t_uchar	*initprimearray(unsigned long sizearr)
{
	int		i;
	t_uchar	*tmp;

	sizearr = sizearr / FT_BIT_MAX + 2;
	tmp = malloc(sizearr * sizeof(t_uchar));
	if (!tmp)
	{
		ft_perror("ERROR: Bad alocation mammory");
		exit(-1);
	}
	i = -1;
	while (++i < sizearr)
		tmp[i] = FT_UCHARMAXVAL;
	return (tmp);
}
