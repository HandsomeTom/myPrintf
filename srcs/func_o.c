/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:52:26 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/07 18:07:22 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_o(int type, va_list ap)
{
	if (type == 1)
		return (ft_itoa_base((unsigned char)va_arg(ap++,
		void *), 8, 0));
	else if (type == 2)
		return (ft_itoa_base((unsigned short)va_arg(ap++,
		void *), 8, 0));
	else if (type == 3)
		return (ft_itoa_base((unsigned long)va_arg(ap++,
		void *), 8, 0));
	else if (type == 4)
		return (ft_itoa_base((unsigned long long)va_arg(ap++,
		void *), 8, 0));
	else
		return (ft_itoa_base(va_arg(ap++, unsigned int), 8, 0));
}
