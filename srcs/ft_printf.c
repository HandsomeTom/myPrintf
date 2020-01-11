/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:15:00 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/11 16:13:41 by tmaarela         ###   ########.fr       */
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

int			start_formatting(char *format, t_flags flags, int *i, va_list ap)
{
	char	*hold;
	char	*tmp;
	int		form;

	format++;
	form = 1;
	flags = store_flags((char *)&(*format));
	form += flags.skip;
	format += flags.skip;
	flags.skip = 0;
	flags = store_length_spec(flags, (char *)&(*format), ap);
	form += flags.skip;
	format += flags.skip;
	tmp = store_data(ap, flags);
	hold = write_output(tmp, flags);
	free(tmp);
	(flags.emptychar == 0) ? ft_putstr(hold) : 0;
	*i += ft_strlen(hold) + flags.emptychar;
	return (form);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_flags		flags;
	int			i;
	char		*tmp;

	va_start(ap, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
			format += start_formatting((char *)format, flags, &i, ap);
		else
		{
			write(1, &(*format), 1);
			i++;
			format++;
		}
	}
	va_end(ap);
	return (i);
}
