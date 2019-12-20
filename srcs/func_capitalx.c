/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_capitalx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:57:59 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 17:59:06 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_capitalx(char *hold, int type, va_list ap)
{
	if (type == 1)
		hold = ft_itoa_base((unsigned char)va_arg(ap++,
		unsigned long long), 16, 1);
	else if (type == 2)
		hold = ft_itoa_base((unsigned short)va_arg(ap++,
		unsigned long long), 16, 1);
	else if (type == 3)
		hold = ft_itoa_base((unsigned long)va_arg(ap++,
		unsigned long long), 16, 1);
	else if (type == 4)
		hold = ft_itoa_base((unsigned long long)va_arg(ap++,
		unsigned long long), 16, 1);
	else
		hold = ft_itoa_base(va_arg(ap++, unsigned int), 16, 1);
	return (hold);
}