/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:26:56 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 18:25:44 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Store the information of our flags into struct flags. Printf is supposed to
** take following flags in this exact order:
** %[flags][width][.precision][length]specifier
** for simplicitys sake I'm refering to all these extra specifiers as flags.
*/ 

#include "../ft_printf.h"

t_flags		pf_flags(char *str)
{
	t_flags	flags;

	flags = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (*str == '0' || *str == '-' || *str == '+'
			|| *str == ' ' || *str == '#')
	{
		if (*str == '0')
			flags.zero = 1;
		else if (*str == '#')
			flags.hash = 1;
		else if (*str == '+')
			flags.sign = 1;
		else if (*str == '-')
			flags.justification = 1;
		else if (*str == ' ')
			flags.space = 1;
		str++;
		flags.skip++;
	}
	return (flags);
}

t_flags		store_flags(char *str)
{
	int		i;
	t_flags	flags;

	flags = pf_flags(str);
	str += flags.skip;
	if (ft_atoi(str))
	{
		flags.width = ft_atoi(str);
		str += ft_numlength(flags.width);
		flags.skip += ft_numlength(flags.width);
	}
	if (*str == '.')
	{
		str++;
		while (*str == '0')
		{
			str++;
			flags.skip++;
		}
		flags.presize = ft_atoi(str);
	}
	flags.skip += (flags.presize > 0) ? ft_numlength(flags.presize) + 1 : 0;
	return (flags);
}
