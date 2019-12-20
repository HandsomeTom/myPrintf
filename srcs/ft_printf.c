/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:15:00 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 17:24:09 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int					ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_flags		flags;
	int			i;
	char		*hold;

	va_start(ap, format);
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
			write_output(hold, flags);
			flags = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
