/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:57:59 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/06 18:19:46 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_x(int type, va_list ap)
{
	if (type == 1)
		return (ft_itoa_base((unsigned char)va_arg(ap++,
		unsigned char), 16, 0));
	else if (type == 2)
		return (ft_itoa_base((unsigned short)va_arg(ap++,
		unsigned short), 16, 0));
	else if (type == 3)
		return (ft_itoa_base((unsigned long)va_arg(ap++,
		unsigned long), 16, 0));
	else if (type == 4)
		return (ft_itoa_base((unsigned long long)va_arg(ap++,
		unsigned long long), 16, 0));
	else
		return (ft_itoa_base((unsigned int)va_arg(ap++, unsigned int), 16, 0));
}
