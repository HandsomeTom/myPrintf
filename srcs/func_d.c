/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:40:37 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/06 18:02:10 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_d(int type, va_list ap)
{
	if (type == 1)
		return (ft_itoa((char)va_arg(ap++, char)));
	if (type == 2)
		return (ft_itoa((short)va_arg(ap++, short)));
	if (type == 3)
		return (ft_itoa((long)va_arg(ap++, long)));
	if (type == 4)
		return (ft_itoa((long long)va_arg(ap++, long long)));
	return (ft_itoa(va_arg(ap++, int)));
}
