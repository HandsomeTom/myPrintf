/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:52:26 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 18:02:26 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_o(char *hold, int type, va_list ap)
{
	if (type == 1)
		hold = ft_itoa_base((unsigned char)va_arg(ap++,
		unsigned long long), 8, 0);
	else if (type == 2)
		hold = ft_itoa_base((unsigned short)va_arg(ap++,
		unsigned long long), 8, 0);
	else if (type == 3)
		hold = ft_itoa_base((unsigned long)va_arg(ap++,
		unsigned long long), 8, 0);
	else if (type == 4)
		hold = ft_itoa_base((unsigned long long)va_arg(ap++,
		unsigned long long), 8, 0);
	else
		hold = ft_itoa_base(va_arg(ap++, unsigned long long), 8, 0);
	return (hold);
}
