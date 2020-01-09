/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:40:37 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/07 18:09:12 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_d(int type, va_list ap)
{
	if (type == 1)
		return (ft_itoa((char)va_arg(ap++, void *)));
	if (type == 2)
		return (ft_itoa((short)va_arg(ap++, void *)));
	if (type == 3)
		return (ft_itoa((long)va_arg(ap++, void *)));
	if (type == 4)
		return (ft_itoa((long long)va_arg(ap++, void *)));
	return (ft_itoa((int)va_arg(ap++, void *)));
}
