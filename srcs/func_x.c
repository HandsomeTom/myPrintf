/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:57:59 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/02 18:05:34 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_x(char *hold, int type, va_list ap)
{
	if (type == 1)
		hold = ft_itoa_base((unsigned char)va_arg(ap++,
		unsigned char), 16, 0);
	else if (type == 2)
		hold = ft_itoa_base((unsigned short)va_arg(ap++,
		unsigned short), 16, 0);
	else if (type == 3)
		hold = ft_itoa_base((unsigned long)va_arg(ap++,
		unsigned long), 16, 0);
	else if (type == 4)
		hold = ft_itoa_base((unsigned long long)va_arg(ap++,
		unsigned long long), 16, 0);
	else
		hold = ft_itoa_base((unsigned int)va_arg(ap++, unsigned int), 16, 0);
	return (hold);
}
