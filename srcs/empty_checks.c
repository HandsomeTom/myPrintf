/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:27:08 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/11 14:41:10 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char					*ft_empty_char(char *str, t_flags flags)
{
	int		i;

	i = ft_strlen(str);
	if ((int)flags.value == 0 && flags.spec == 'c')
	{
		str[i - 1] = '\0';
		if (flags.justification == 0)
			ft_putstr(str);
		write(1, "\0", 1);
		if (flags.justification == 1)
			ft_putstr(str);
		return (str);
	}
	return (str);
}

int						if_str_empty(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int						neg_check(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '-')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
