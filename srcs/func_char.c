/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:29:18 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/07 17:19:06 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_char(va_list ap)
{
	va_list	apc;
	char	*ret;

	va_copy(apc, ap);
	if (va_arg(apc, int) == 0)
	{
		va_arg(ap++, int);
		return (ft_strjoin("", " "));
	}
	if (!(ret = ft_strnew(0)))
		return (NULL);
	ret = ft_memset(ret, va_arg(ap++, int), 1);
	ret[1] = '\0';
	return (ret);
}
