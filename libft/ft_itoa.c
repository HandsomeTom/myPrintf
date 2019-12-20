/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:22:20 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/05 15:35:57 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_numlen(int num)
{
	int ret;

	ret = 1;
	if (num < 0)
		ret++;
	while (num / 10 != 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*str;

	i = ft_numlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (i--)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
