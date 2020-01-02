/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:40:37 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/02 18:00:46 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_u(char *hold, int type, va_list ap)
{
	if (type == 1)
		return (hold = ft_itoa_base((unsigned char)va_arg(ap++,
		unsigned char), 10, 0));
	else if (type == 2)
		return (hold = ft_itoa_base((unsigned short)va_arg(ap++,
		unsigned short), 10, 0));
	else if (type == 3)
		return (hold = ft_itoa_base((unsigned long)va_arg(ap++,
		unsigned long), 10, 0));
	else if (type == 4)
		return (hold = ft_itoa_base((unsigned long long)va_arg(ap++,
		unsigned long long), 10, 0));
	else
		return (ft_itoa_base((unsigned int)va_arg(ap++, unsigned int), 10, 0));
}
