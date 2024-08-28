/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:10:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/28 17:32:13 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/getnearprime.h"
#include <stdio.h>

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
	printf("PRIME NUMBER:\t%d\n", *(int *)data);
}

int	main()
{
	t_ulong	num = 10523;

	num = getnearestprime(num);
	printf("RSULT:\t%ld\n", num);
	return (0);
}
