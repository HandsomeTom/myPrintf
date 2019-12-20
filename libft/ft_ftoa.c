/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:34:26 by tomtom            #+#    #+#             */
/*   Updated: 2019/12/19 12:59:43 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static long double			ft_change_prec(long double n, int prec)
{
	int i;

	i = 0;
	if (n >= 1 || n <= -1)
		while (i < prec)
		{
			n = n * 10;
			i++;
		}
	return (n);
}

static int	ft_numlen(long double num)
{
	int ret;
	unsigned long long n;

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
	long double	nb;
	char		*str;
	int			len;
	int			neg;

	neg = (num < 0) ? 1 : 0;
	nb = (num < 0) ? -num : num;
	prec = (prec == -1) ? 6 : prec;
	nb = ft_change_prec(nb, prec);
	nb += 0.5;
	len = ft_numlen(nb) + (dot > 0 && prec == 0) + (prec > 0) + (prec > 0 && num < 1 && num > - 1);
	if (!(str = (char *)ft_strnew(len + neg)))
		return (NULL);
	while ((len-- + neg > 0))
	{
		if (dot == 1 && prec == 0)
			str[len-- + neg] = '.';
		str[len + neg] = (((unsigned long long)nb % 10) + 48);
		(--prec == 0) ? str[--len + neg] = '.' : 1;
		nb /= 10;
	}
	neg == 1 ? str[0] = '-' : 1;
	return (str);
}
