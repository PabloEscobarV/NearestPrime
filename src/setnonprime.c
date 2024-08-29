/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnonprime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:59:39 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/29 20:06:16 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/gnp_service.h"
#include "../libft/libft.h"

static t_ulong	getmin(t_ulong prime, t_ulong min)
{
	if (min == prime)
		min *= prime;
	if (min < prime)
		min = prime + 1;
	while (min % prime)
		++min;
	return (min);
}

static void	setnprm(t_uchar *primearr, t_ulong max, t_ulong min, t_ulong prm)
{
	t_ulong	i;

	if (min < 2)
		i = getmin(prm, prm);
	else
		i = getmin(prm, min);
	while (i <= max)
	{
		resetbit(&(primearr[(i - min) / FT_BIT_MAX]),
			(i - min) % FT_BIT_MAX);
		i += prm;
	}
}

t_uchar	*setnonprime(t_llist *primenums, t_ulong max, t_ulong min)
{
	t_uchar	*primearr;

	primearr = initprimearray(max - min + 2);
	if (min < 2)
	{
		resetbit(&(*primearr), 0);
		resetbit(&(*primearr), 1);
	}
	while (primenums && *(int *)primenums->data <= max)
	{
		setnprm(primearr, max,
			min, *(int *)primenums->data);
		primenums = primenums->next;
	}
	return (primearr);
}
