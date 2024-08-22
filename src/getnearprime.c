/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnearprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/22 20:26:58 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

t_uchar	*initarray(unsigned long num)
{
	t_uchar	*tmp;

	tmp = malloc((num + 1) * sizeof(t_uchar));
	if (!tmp)
	{
		ft_perror("ERROR: Bad alocation mammory");
		exit(-1);
	}
	*tmp = 0;
	tmp[1] = 0;
	return (tmp);
}

t_uchar	*ft_getmarkprimes(unsigned long num)
{
	unsigned long		j;
	unsigned long		i;
	t_uchar				*tmp;

	if (num < 2)
		return (NULL);
	tmp = initarray(num);
	i = 1;
	while (++i <= num)
		tmp[i] = 1;
	i = 1;
	while (++i <= num)
	{
		if (tmp[i])
		{
			j = i * i;
			while (j <= num)
			{
				tmp[j] = 0;
				j += i;
			}
		}
	}
	return (tmp);
}