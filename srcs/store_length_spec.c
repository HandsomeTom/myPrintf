/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_length_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:07:54 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/13 17:43:33 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			check_len(char *str)
{
	if (str[0] == 'h' && str[1] == 'h')
		return (1);
	if (str[0] == 'h' && str[1] != 'h')
		return (2);
	if (str[0] == 'l' && str[1] != 'l')
		return (3);
	if (str[0] == 'l' && str[1] == 'l')
		return (4);
	if (str[0] == 'L')
		return (5);
	return (0);
}

int					check_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X'
		|| c == 'o' || c == 's' || c == 'f' || c == '%'
		|| c == 'p' || c == 'c' || c == 'u')
		return (c);
	return (0);
}

static int			check_if_int(int schar)
{
	if (schar == 'd' || schar == 'i' || schar == 'u'
		|| schar == 'o' || schar == 'x' || schar == 'X'
		|| schar == 'f' || schar == 'p')
		return (1);
	return (0);
}

static long long	get_arg_value(va_list ap)
{
	va_list		apc;
	long long	ret;

	ret = 0;
	if (ap)
	{
		va_copy(apc, ap);
		ret = (long long)va_arg(apc, void *);
	}
	return (ret);
}

t_flags				store_length_spec(t_flags flags, char *str, va_list ap)
{
	if (*str == 'l' || *str == 'h' || *str == 'L')
	{
		flags.length = check_len(str);
		while (*str == 'l' || *str == 'h' || *str == 'L')
		{
			str++;
			flags.skip++;
		}
	}
	flags.spec = check_specifier(str[0]);
	if (flags.spec != 0)
		flags.skip++;
	flags.integer = check_if_int(flags.spec);
	if (flags.integer == 1 || flags.spec == 'c')
		flags.value = get_arg_value(ap);
	flags = flags_conflict_fix(flags);
	return (flags);
}
