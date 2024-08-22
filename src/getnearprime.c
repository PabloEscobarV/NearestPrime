/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnearprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/22 20:42:27 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/gnp_service.h"
#include "../libft/libft.h"
#include "../ft_pow/hdrs/ft_pow.h"
#include <stdlib.h>

t_ulong	setstartnum(t_ulong num)
{
	t_ulong	tmp;

	if (num <= GNP_MAXNUM)
		return (num);
	tmp = (t_ulong)ft_sqrt(num);
	while (tmp > GNP_MAXNUM)
		tmp = (t_ulong)ft_sqrt(num);
	return (tmp);
}

t_ulong	getnearprime(t_ulong num)
{
	t_uchar	*startprimes;
	
	startprimes = ft_getmarkprimes(setstartnum(num));
	if (!startprimes)
		return (0);
	
}
