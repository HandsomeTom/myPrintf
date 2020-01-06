/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:34:26 by tomtom            #+#    #+#             */
/*   Updated: 2020/01/06 17:13:35 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static long double			ft_change_prec(long double n, int prec)
{
	int i;

	i = 0;
	while (i < prec)
	{
		n = n * 10;
		i++;
	}
	return (n);
}

static int					ft_numlen(long double num)
{
	int					ret;
	unsigned long long	n;

	ret = 1;
	while (num > (long double)10000000000000000000.0)
	{
		num /= 10;
		ret++;
	}
	n = (unsigned long long)num;
	while (n / 10 != 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char						*ft_ftoa(long double num, int prec, int dot)
{
	long double	n;
	char		*str;
	int			len;
	int			neg;
	int			z;

	neg = (num < 0) ? 1 : 0;
	n = (num < 0) ? -num : num;
	z = ((long long)num == 0 && num != 0.0) ? 1 : 0;
	(z == 1) ? n += 1 : 0;
	prec = (prec == -1) ? 6 : prec;
	n = ft_change_prec(n, prec) + 0.4;
	len = ft_numlen(n) + (dot > 0 && prec == 0) + (prec > 0) + (prec > 0 && z);
	if (!(str = (char *)ft_strnew(len + neg)))
		return (NULL);
	while ((len-- + neg - z > 0))
	{
		(dot == 1 && prec == 0) ? str[len-- + neg] = '.' : 0;
		str[len + neg - z] = (((unsigned long long)n % 10) + 48);
		(--prec == 0) ? str[--len + neg - z] = '.' : 1;
		n /= 10;
	}
	(z == 1) ? str[neg] = '0' : 0;
	neg == 1 ? str[0] = '-' : 1;
	return (str);
}
