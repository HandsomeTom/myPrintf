/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:26:35 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/06 18:36:49 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** After saving all the flags into the struct flags we look at the specifier
** and perform the necessary function to store the data into printf.c's char
** "hold". Inside each function is simple if else jungle that typecasts the
** data if length is specified.
*/

#include "../ft_printf.h"

char		*store_string(va_list ap)
{
	va_list	apc;

	va_copy(apc, ap);
	if (va_arg(apc, size_t) == 0)
	{
		va_arg(ap++, size_t);
		return (ft_strjoin("", "(null)"));
	}
	else
		return (ft_strjoin("",va_arg(ap++, char *)));
}

char		*store_data(va_list ap, t_flags flags)
{
	if (flags.spec == 'd' || flags.spec == 'i')
		return (func_d(flags.length, ap));
	else if (flags.spec == 's')
		return (store_string(ap));
	else if (flags.spec == 'c')
		return (func_char(ap));
	else if (flags.spec == 'p')
		return (ft_pointer_to_string(va_arg(ap++, unsigned long long *)));
	else if (flags.spec == 'o')
		return (func_o(flags.length, ap));
	else if (flags.spec == 'x')
		return (func_x(flags.length, ap));
	else if (flags.spec == 'X')
		return (func_capitalx(flags.length, ap));
	else if (flags.spec == 'u')
		return (func_u(flags.length, ap));
	else if (flags.spec == 'f')
		return (func_f(flags.length, ap, flags));
	else if (flags.spec == '%')
		return(ft_strjoin("", "%"));
	return (ft_strnew(0));
}
