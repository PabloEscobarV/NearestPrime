/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnonprime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:59:39 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/28 17:04:10 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/gnp_service.h"
#include "../libft/libft.h"

static t_ulong	getmin(t_ulong prime, t_ulong minnum)
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
	t_ulong	i;

	if (minnum < 2)
		i = getmin(prm, prm);
	else
		i = getmin(prm, minnum);
	while (i <= maxnum)
	{
		resetbit(&(primearr[(i - minnum) / FT_BIT_MAX]),
			(i - minnum) % FT_BIT_MAX);
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