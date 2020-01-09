/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:40:05 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/09 19:08:13 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Now that the flags etc are stored and our string contains the right data,
** it's time to take that string and apply whatever spacing, justification,
** precision etc. is to be added. We return the final string to printf and
** print it out.
*/

#include "../ft_printf.h"
#include <stdio.h>

static char				*store_width(char *str, int len, t_flags flags, int ch)
{
	char	*ret;

	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	ft_memset(ret, ch, len);
	ret[len] = '\0';
	if (flags.justification == 0)
		str = ft_strjoin(ret, str);
	else
		str = ft_strjoin(str, ret);
	free(ret);
	return (str);
}

static int				neg_check(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '-')
	{
		if (str[i] == '-')
			return(1);
		i++;
	}
	return (0);
}

static char				*store_pre_int(char *str, int len, int type, int value)
{
	char	*ret;
	int		i;

	i = 0;
	if (value == 0 && ((type != 'd' && type != 'i') || len <= 0))
		str = ft_strjoin("", "");
	(value == 0 && ((type != 'd' && type != 'i') || len <= 0)) ? len++ : 0;
	while (str[i] == ' ' || str[i] == '-')
	{
		if (str[i] == '-')
			len++;
		i++;
	}
	if (len <= 0)
		return (str);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	if (type == 'd' || type == 'i' || type == 'u' || type == 'o'
		|| type == 'x' || type == 'X')
		ft_memset(ret, '0', len);
	ret[len] = '\0';
	str = ft_strjoin(ret, str);
	free(ret);
	return (str);
}

static char				*store_hash_x(char *str, t_flags flags, int len)
{
	int		i;

	i = 0;
	if (flags.spec == 'x' && flags.value != 0)
	{
		if (flags.width <= len || (flags.justification == 1 && flags.width <= 2))
			return (ft_strjoin("0x", str));
		if (flags.width == len + 1 && flags.justification == 0)
			return (ft_strjoin("0x", ft_strsub(str, 1, ft_strlen(str) - 1)));
		if (flags.width > 2 && flags.zero == 0 && flags.justification == 0)
		{
			if (flags.presize <= 0)
				i = flags.width - len - 2;
			else
				i = flags.width - flags.presize - 2;
			str[i] = '0';
			str[i + 1] = 'x';
		}
		else if (flags.width > 2 && flags.zero == 1 && flags.justification == 0)
		{
			str[i] = '0';
			str[i + 1] = 'x';
		}
		else if (flags.justification == 1 && flags.width > 2)
			return(ft_strjoin("0x", ft_strsub(str, 0, ft_strlen(str) - 2 + (flags.width == len + 1))));
	}
	return (str);
}

static char				*store_hash_cap_x(char *str, t_flags flags, int len)
{
	int		i;

	i = 0;
	if (flags.spec == 'X' && flags.value != 0)
	{
		if (flags.width <= len || (flags.justification == 1 && flags.width <= 2))
			return (ft_strjoin("0X", str));
		if (flags.width == len + 1 && flags.justification == 0)
			return (ft_strjoin("0X", ft_strsub(str, 1, ft_strlen(str) - 1)));
		if (flags.width > 2 && flags.zero == 0 && flags.justification == 0)
		{
			if (flags.presize <= 0)
				i = flags.width - len - 2;
			else
				i = flags.width - flags.presize - 2;
			str[i] = '0';
			str[i + 1] = 'X';
		}
		else if (flags.width > 2 && flags.zero == 1 && flags.justification == 0)
		{
			str[i] = '0';
			str[i + 1] = 'X';
		}
		else if (flags.justification == 1 && flags.width > 2)
			return(ft_strjoin("0X", ft_strsub(str, 0, ft_strlen(str) - 2 + (flags.width == len + 1))));
	}
	return (str);
}

static char				*store_hash_o(char *str, t_flags flags, int len)
{
	int		i;

	i = 0;
	if (flags.spec == 'o' && flags.value != 0)
	{
		if ((flags.width <= len && flags.presize <= 0) || (flags.justification == 1 && flags.width <= 2))
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
		{
			str[i] = '0';
		}
		else if (flags.justification == 1) //&& flags.width > len)
			return(ft_strjoin("0", ft_strsub(str, 0, ft_strlen(str) - 1)));
	}
	if (flags.value == 0 && flags.presize == 0)
		return (ft_strjoin("0", str));
	return (str);
}
// static char				*store_hash_o(char *str, t_flags flags, int len)
// {
// 	int		i;

// 	i = 0;
// 	if (flags.spec == 'o')
// 	{
// 		if (flags.width <= 1 && flags.presize <= 0 && ((flags.value != 0 || flags.presize == 0)))
// 			return (ft_strjoin("0", str));
// 		if (flags.width > 1 && flags.zero == 0 && flags.justification == 0)
// 		{
// 			if (flags.presize <= 0)
// 				i = flags.width - len - 1;
// 			else
// 				i = flags.width - flags.presize - 1;
// 			str[i] = '0';
// 		}
// 		else if (flags.width > 1 && flags.zero == 1 && flags.justification == 0)
// 			str[i] = '0';
// 		else if (flags.width > 1 && flags.justification == 1)
// 			str = ft_strjoin("0", ft_strsub(str, 0, ft_strlen(str) - 1));
// 	}
// 	return (str);
// }

static char				*store_hash(char *str, t_flags flags)
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

static int				if_str_empty(char *str)
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

static char				*store_sign(char *str, t_flags flags)
{
	int len;
	int empty;

	empty = if_str_empty(str);
	len = ft_numlenbase(flags.value, 10);
	if (flags.width > len && flags.justification == 1)
			return (ft_strjoin("+", ft_strsub(str, 0, ft_strlen(str) - 1)));
	else if	(flags.width > len && flags.zero == 0)
	{
		if (flags.presize > len)
			str[flags.width - len - (flags.presize - len) - 1] = '+';
		else
			str[flags.width - len - empty] = '+';
		return (str);
	}
	else if (flags.width > len && flags.zero == 1)
	{
		str[0] = '+';
		return (str);
	}
	return (ft_strjoin("+", str));
}

static char					*store_pre_str(char *str, t_flags flags)
{
	char *append;

	if (flags.spec == 's')
		return (ft_strsub(str, 0, flags.presize));
	if (flags.spec == 'p')
	{
		if ((int)flags.value == 0 && flags.presize == 0)
			return (ft_strsub(str, 0, 2));
		else
		{
			if (flags.presize > ft_strlen(str) - 2)
			{
				str = ft_strsub(str, 2, ft_strlen(str) - 2);
				if (!(append = (char *)malloc(flags.presize - ft_strlen(str) + 2)))
					return (NULL);
				ft_memset(append, '0', flags.presize - ft_strlen(str) + 2);
				append[1] = 'x';
				str = ft_strjoin(append, str);
				free(append);
				return (str);
			}
		}
	}
	return (str);
}

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

char					*write_output(char *str, t_flags flags)
{
	int		len;
	int		c;

	len = ft_strlen(str);
	flags.space = (neg_check(str)) ? 0 : flags.space;
	c = (flags.zero > 0) ? '0' : ' ';
	if (flags.integer == 1 && flags.presize >= 0 && flags.spec != 'p')
		str = store_pre_int(str, flags.presize - len, flags.spec, flags.value);
	else if ((flags.spec == 's' || flags.spec == 'p') && flags.presize >= 0)
		str = store_pre_str(str, flags);
	if (flags.width > ft_strlen(str))
		str = store_width(str, flags.width - ft_strlen(str) - flags.space,
		flags, c);
	if ((flags.spec == 'o' || flags.spec == 'x' || flags.spec == 'X') && flags.hash == 1)
		str = store_hash(str, flags);
	if ((flags.spec == 'd' || flags.spec == 'i')
		&& flags.sign == 1 && (int)flags.value >= 0)
		str = store_sign(str, flags);
	if (flags.space == 1 && flags.integer == 1 && flags.spec != 'u')
		str = ft_strjoin(" ", str);
	if (flags.integer == 1)
		str = fix_negative_sign(str, flags);
	if (flags.emptychar == 1)
		str = ft_empty_char(str, flags);
	return(str);
}
