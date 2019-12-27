/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:15:00 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/27 17:51:21 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FT_PRINTF()
** The goal of this project is to re-create libc's printf function. It needs
** to take into account the specifiers d i u o x X f c s p and %%.
** In addition the following sub-specifiers (later referred to as flags)
** need to be taken into account: + - # 0 and space, along with width,
** precision and length.
*/

#include "../ft_printf.h"

int					ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_flags		flags;
	int			i;
	char		*hold;

	va_start(ap, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = store_flags((char *)&(*format));
			format += flags.skip;
			flags.skip = 0;
			flags = store_length_spec(flags, (char *)&(*format), ap);
			format += flags.skip;
			hold = store_data(ap, flags);
			hold = write_output(hold, flags);
			ft_putstr(hold);
			i += ft_strlen(hold);
			flags = (t_flags){0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0};
		}
		else
		{
			write(1, &(*format), 1);
			i++;
			format++;
		}
	}
	return (i);
}
