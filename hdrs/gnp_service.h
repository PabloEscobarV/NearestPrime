/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnp_service.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:27:25 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/28 17:11:47 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../libft/libft.h"

#define GNP_MAXARRSIZE	8000

t_ulong	getnearestprime(t_ulong	num);
/////////////////////////////////GET LLIST PRIMES\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_uchar	*setnonprime(t_llist *primenums, t_ulong maxnum, t_ulong minnum);
/////////////////////////////////GET LLIST PRIMES\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_llist	*ft_getllistprimes(t_uchar *mrkprimes, t_ulong maxnum, t_ulong minnnum);
/////////////////////////////////////TOOLS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_ulong	getelemprimearrsizze(t_ulong maxnum);
t_ulong	getprime(t_ulong maxnum, t_uchar *primearr);
t_uchar	*initprimearray(unsigned long sizearr);
