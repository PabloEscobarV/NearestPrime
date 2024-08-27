/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnearprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/27 16:52:55 by Pablo Escob      ###   ########.fr       */
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

t_ulong	getmin(t_ulong prime, t_ulong minnum)
{
	if (minnum == prime)
		minnum *= prime;
	if (minnum < prime)
		minnum = prime + 1;
	while (minnum % prime)
		++minnum;
	return (minnum);
}

static void	setnprm(t_uchar *primearr, t_ulong maxnum, t_ulong minnum, t_ulong prm)
{
	t_uint	byte;
	t_uint	bit;
	t_uint	i;

	if (minnum < 2)
		i = getmin(prm, prm);
	else
		i = getmin(prm, minnum);
	while (i <= maxnum)
	{
		bit = (i - minnum) % FT_BIT_MAX;
		byte = (i - minnum) / FT_BIT_MAX;
		resetbit(&(primearr[byte]),
			bit);
		i += prm;
	}		
}

t_uchar	*setnonprime(t_llist *primenums, t_ulong maxnum, t_ulong minnum)
{
	t_uchar *primearr;

	primearr = initprimearray(maxnum - minnum + 2);
	if (minnum < 2)
	{
		resetbit(&(*primearr), 0);
		resetbit(&(*primearr), 1);
	}
	while (primenums && *(int *)primenums->data <= maxnum)
	{
		setnprm(primearr, maxnum,
			minnum, *(int *)primenums->data);
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

int main()
{
	t_ulong	maxnum = 1001;
	t_ulong	minnum = 900;
	t_uchar	*primearr;
	t_llist	*elementprimes;
	t_llist	*primenum;

	elementprimes = ft_getprimes((t_ulong)(ft_sqrt(maxnum)));
	// llistiter(elementprimes, printdata);
	// printmarkbits(elementprimes, 0);
	primearr = setnonprime(elementprimes, maxnum, minnum);
	// printmarkbits(primearr, minnum);
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
