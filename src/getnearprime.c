/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnearprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/28 17:01:15 by Pablo Escob      ###   ########.fr       */
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
	llistclear(&primenum, free);
	return (tmp);
}

void	printmarkbits(t_uchar *markbits, t_ulong minnum)
{
	int	i;
	int	bit;

	i = -1;
	while (markbits[++i] != FT_UCHARMAXVAL)
	{
		bit = 0;
		while (bit < FT_BIT_MAX)
		{
			if (getbit(&markbits[i], bit))
				printf ("TEST: PRIME NUMBER:\t%ld\n", i * FT_BIT_MAX + minnum + bit);
			++bit;
		}
	}
}

void	printdata(void *data)
{
	printf("PRIME NUMBER:\t%ld\n", *(int *)data);
}

int	main()
{
	t_ulong	num = 10523;

	num = getnearestprime(num);
	printf("RSULT:\t%ld\n", num);
	return (0);
}

// int main()
// {
// 	t_ulong	maxnum = 1001;
// 	t_ulong	minnum = 900;
// 	t_uchar	*primearr;
// 	t_llist	*elementprimes;
// 	t_llist	*primenum;

// 	elementprimes = ft_getprimes((t_ulong)(ft_sqrt(maxnum)));
// 	// llistiter(elementprimes, printdata);
// 	// printmarkbits(elementprimes, 0);
// 	primearr = setnonprime(elementprimes, maxnum, minnum);
// 	// printmarkbits(primearr, minnum);
// 	primenum = ft_getllistprimes(primearr, maxnum, minnum);
// 	llistiter(primenum, printdata);
// 	return (0);
// }

// t_ulong	getnearprime(t_ulong maxnum)
// {
// 	t_ulong	sizestartarr;
// 	t_uchar	*startarr;
	
// 	sizestartarr = getelemprimearrsizze(maxnum);
// 	startarr = ft_getmarkprimes(sizestartarr);
// 	if (!startarr)
// 		return (0);
// 	if (sizestartarr <= maxnum)
// 		return (getprime(sizestartarr, startarr));
	
// }
