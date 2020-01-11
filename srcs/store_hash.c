/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:23:57 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/11 16:23:00 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char				*str_embed(char *str, int i, int cap)
{
	char x;

	if (cap == 1)
		x = 'X';
	else
		x = 'x';
	str[i] = '0';
	str[i + 1] = x;
	return (str);
}

static char				*store_hash_x(char *str, t_flags flags, int len)
{
	int		i;

	i = 0;
	if (flags.spec == 'x' && flags.value != 0)
	{
		if (flags.width <= len || (flags.justification == 1
			&& flags.width <= 2))
			return (ft_strjoin("0x", str));
		if (flags.width == len + 1 && flags.justification == 0)
			return (ft_strjoin("0x", ft_strsub(str, 1, ft_strlen(str) - 1)));
		if (flags.width > 2 && flags.zero == 0 && flags.justification == 0)
		{
			if (flags.presize <= 0)
				i = flags.width - len - 2;
			else
				i = flags.width - flags.presize - 2;
			str = str_embed(str, i, 0);
		}
		else if (flags.width > 2 && flags.zero == 1 && flags.justification == 0)
			str = str_embed(str, i, 0);
		else if (flags.justification == 1 && flags.width > 2)
			return (ft_strjoin("0x", ft_strsub(str, 0, ft_strlen(str) - 2
			+ (flags.width == len + 1))));
	}
	return (str);
}

static char				*store_hash_cap_x(char *str, t_flags flags, int len)
{
	int		i;

	i = 0;
	if (flags.spec == 'X' && flags.value != 0)
	{
		if (flags.width <= len || (flags.justification == 1
			&& flags.width <= 2))
			return (ft_strjoin("0X", str));
		if (flags.width == len + 1 && flags.justification == 0)
			return (ft_strjoin("0X", ft_strsub(str, 1, ft_strlen(str) - 1)));
		if (flags.width > 2 && flags.zero == 0 && flags.justification == 0)
		{
			if (flags.presize <= 0)
				i = flags.width - len - 2;
			else
				i = flags.width - flags.presize - 2;
			str = str_embed(str, i, 1);
		}
		else if (flags.width > 2 && flags.zero == 1 && flags.justification == 0)
			str = str_embed(str, i, 1);
		else if (flags.justification == 1 && flags.width > 2)
			return (ft_strjoin("0X", ft_strsub(str, 0, ft_strlen(str) - 2
			+ (flags.width == len + 1))));
	}
	return (str);
}

static char				*store_hash_o(char *str, t_flags flags, int len)
{
	int		i;

	i = 0;
	if (flags.spec == 'o' && flags.value != 0)
	{
		if ((flags.width <= len && flags.presize <= 0)
			|| (flags.justification == 1 && flags.width <= 2))
			return (ft_strjoin("0", str));
		if (flags.width > len && flags.zero == 0 && flags.justification == 0)
		{
			if (flags.presize < 0)
				i = flags.width - len - 1;
			else
				i = flags.width - flags.presize - 1;
			str[i] = '0';
		}
		else if (flags.zero == 1 && flags.justification == 0)
			str[i] = '0';
		else if (flags.justification == 1)
			return (ft_strjoin("0", ft_strsub(str, 0, ft_strlen(str) - 1)));
	}
	if (flags.value == 0 && flags.presize == 0)
		return (ft_strjoin("0", str));
	return (str);
}

char					*store_hash(char *str, t_flags flags)
{
	if (flags.spec == 'x')
	{
		str = store_hash_x(str, flags, ft_numlength_base(flags.value, 16));
		return (str);
	}
	else if (flags.spec == 'X')
	{
		str = store_hash_cap_x(str, flags, ft_numlength_base(flags.value, 16));
		return (str);
	}
	else if (flags.spec == 'o')
	{
		str = store_hash_o(str, flags, ft_numlength_base(flags.value, 8));
		return (str);
	}
	return (str);
}
