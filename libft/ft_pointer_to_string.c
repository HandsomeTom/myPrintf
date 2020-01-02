/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:33:19 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/02 18:16:41 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_numlen(unsigned long long num, int base)
{
	int ret;

	ret = 1;
	while (num / base != 0)
	{
		num /= base;
		ret++;
	}
	return (ret);
}

char		*ft_pointer_to_string(void *pointer)
{
	char				*ps;
	unsigned long long	p;

	p = (unsigned long long)pointer;
	if (p == 0)
	{
		ps = ft_strjoin("", "0x0");
		return (ps);
	}
	if (!(ps = (char *)malloc(ft_numlen(p, 16) + 2)))
		return (NULL);
	ps = ft_itoa_base((unsigned long long)p, 16, 0);
	ps = ft_strjoin("0x", ps);
	return (ps);
}
