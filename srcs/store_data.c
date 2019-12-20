/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:26:35 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 17:53:41 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** After saving all the flags into the struct flags we look at the specifier
** and perform the necessary function to store the data into printf.c's char
** "hold". Inside each function is simple if else jungle that typecasts the
** data if length is specified.
*/

#include "../ft_printf.h"

char		*store_data(va_list ap, t_flags flags)
{
	char	*hold;

	hold = ft_strnew(0);
	if (flags.spec == 'd' || flags.spec == 'i')
		return (func_d(hold, flags.length, ap));
	else if (flags.spec == 's')
		hold = ft_strdup(va_arg(ap++, char *));
	else if (flags.spec == 'c')
		hold = func_char(ap, hold);
	else if (flags.spec == 'p')
		hold = ft_pointer_to_string(va_arg(ap++, unsigned long long *));
	else if (flags.spec == 'o')
		return (func_o(hold, flags.length, ap));
	else if (flags.spec == 'x')
		return (func_x(hold, flags.length, ap));
	else if (flags.spec == 'X')
		return (func_capitalx(hold, flags.length, ap));
	else if (flags.spec == 'u')
		return (func_u(hold, flags.length, ap));
	else if (flags.spec == 'f')
		return (func_f(hold, flags.length, ap, flags));
	else if (flags.spec == '%')
		hold = ft_memset(hold, '%', 1);
	return (hold);
}
