/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnearprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/29 20:05:04 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/gnp_service.h"
#include "../libft/libft.h"
#include "../ft_pow/hdrs/ft_pow.h"
#include <stdlib.h>
#include <stdio.h>

static t_ulong	getminnum(t_ulong num)
{
	t_ulong	i;
	t_ulong	tmp;

	if (num <= GNP_MAXARRSIZE)
		return (0);
	tmp = ft_sqrt(num);
	i = 1;
	while (tmp >= GNP_MAXARRSIZE)
	{
		tmp = ft_sqrt(tmp);
		++i;
	}
	return (num - tmp * i);
}

static t_ulong	findnearprime(t_llist *primesnum)
{
	if (primesnum->previous)
		return (*(t_ulong *)primesnum->previous->data);
	return (*(t_ulong *)primesnum->data);
}

t_ulong	getnearestprime(t_ulong	num)
{
	t_ulong	tmp;
	t_uchar	*primearr;
	t_llist	*elementprimes;
	t_llist	*primenum;

	tmp = getelemprimearrsizze(num);
	elementprimes = ft_getprimes(tmp);
	if (!elementprimes)
		return (0);
	if (tmp >= num)
	{
		tmp = findnearprime(elementprimes);
		llistclear(&elementprimes, free);
		return (tmp);
	}
	primearr = setnonprime(elementprimes, num, getminnum(num));
	primenum = ft_getllistprimes(primearr, num, getminnum(num));
	free(primearr);
	tmp = findnearprime(primenum);
	llistclear(&elementprimes, free);
	llistclear(&primenum, free);
	return (tmp);
}
