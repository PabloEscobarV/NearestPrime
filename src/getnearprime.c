/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnearprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/24 21:24:56 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/gnp_service.h"
#include "../libft/libft.h"
#include "../ft_pow/hdrs/ft_pow.h"
#include <stdlib.h>
#include <stdio.h>

t_ulong	setsizestartprime(t_ulong maxnum)
{
	t_ulong	tmp;

	if (maxnum <= GNP_MAXARRSIZE)
		return (maxnum);
	return (GNP_MAXARRSIZE);
}

t_ulong	getprime(t_ulong maxnum, t_uchar *primearr)
{
	while (maxnum >= 0)
	{
		if (primearr[maxnum])
			break;
		--maxnum;
	}
	free(primearr);
	return (maxnum);
}

static t_uchar	*initprimearray(unsigned long sizearr)
{
	int		i;
	t_uchar	*tmp;

	sizearr = sizearr / FT_BIT_MAX + 1;
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

t_ulong	getmin(t_ulong prime, t_ulong minnum)
{
	if (minnum == prime)
		minnum *= prime;
	while (minnum % prime)
		++minnum;
	return (minnum);
}

static void	setnprm(t_uchar *primearr, t_ulong maxnum, t_ulong minnum, t_ulong prm)
{
	t_uint	i;

	i = minnum;
	while (i <= maxnum)
	{
		resetbit(&(primearr[(i - minnum) / FT_BIT_MAX]), (i - minnum) % FT_BIT_MAX);
		i += prm;
	}		
}

t_uchar	*setnonprime(t_llist *primenums, t_ulong maxnum, t_ulong minnum)
{
	t_ulong	tmp;
	t_uchar *primearr;

	primearr = initprimearray(maxnum - minnum + 2);
	while (primenums)
	{
		tmp = getmin(*(int *)primenums->data, minnum);
		setnprm(primearr, maxnum,
			tmp, *(int *)primenums->data);
		primenums = primenums->next;
	}
	return (primearr);
}

// t_uchar	*setarrprimes(t_uchar *startarr, t_ulong sizearr, t_ulong minnum)
// {
// 	t_ulong	i;
// 	t_ulong	i;
// 	t_uchar	*primearr;

// 	primearr = initprimearray(sizearr);
// 	setnonprime(primearr, startarr, sizearr, minnum);
// 	return (primearr);
// 	// i = 0;
// 	// while (i < sizearr)
// 	// {
// 	// 	if (primearr[i])
// 	// 	{
// 	// 		i = i * i;
// 	// 		while (i < sizearr)
// 	// 		{
// 	// 			primearr[i] = 0;
// 	// 			i += i;
// 	// 		}
// 	// 	}
// 	// }
// }

void	printdata(void *data)
{
	printf("PRIME NUMBER:\t%ld\n", *(int *)data);
}

static void	*crtint(unsigned long maxnum)
{
	unsigned long	*tmp;

	tmp = malloc(sizeof(unsigned long));
	*tmp = maxnum;
	return ((void *)tmp);
}

t_llist	*ft_getllistprimes(t_uchar *markedprimes, t_ulong maxnum, t_ulong minnum)
{
	t_uint	bit;
	t_ulong	i;
	t_llist	*primenums;

	if (!markedprimes)
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
			if (getbit(&(markedprimes[i]), bit))
				llistadd_back(&primenums, llistnewnode(
						crtint(i * FT_BIT_MAX + bit + minnum)));
			++bit;
		}
		++i;
	}
	return (primenums);
}

int main()
{
	t_ulong	maxnum = 113;
	t_ulong	minnum = 101;
	t_uchar	*primearr;
	t_llist	*elementprimes;
	t_llist	*primenum;

	elementprimes = ft_getprimes((t_ulong)ft_sqrt(maxnum));
	primearr = setnonprime(elementprimes, maxnum, minnum);
	primenum = ft_getllistprimes(primearr, maxnum, minnum);
	llistiter(primenum, printdata);
	return (0);
}

// t_ulong	getnearprime(t_ulong maxnum)
// {
// 	t_ulong	sizestartarr;
// 	t_uchar	*startarr;
	
// 	sizestartarr = setsizestartprime(maxnum);
// 	startarr = ft_getmarkprimes(sizestartarr);
// 	if (!startarr)
// 		return (0);
// 	if (sizestartarr <= maxnum)
// 		return (getprime(sizestartarr, startarr));
	
// }
