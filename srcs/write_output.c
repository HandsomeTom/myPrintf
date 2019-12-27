/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:40:05 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/27 17:52:32 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Now that the flags etc are stored and our string contains the right data,
** it's time to take that string and apply whatever spacing, justification,
** precision etc. is to be added. We return the final string to printf and
** print it out.
*/

#include "../ft_printf.h"

static char				*store_width(char *str, int len, int just, int ch)
{
	char	*ret;

	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	ft_memset(ret, ch, len);
	ret[len] = '\0';
	if (just == 0)
		return (ft_strjoin(ret, str));
	else
		return (ft_strjoin(str, ret));
}

static char				*store_pre_int(char *str, int len, int type)
{
	char	*ret;

	if (len <= 0)
		return (str);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	if (type == 'd' || type == 'i' || type == 'u' || type == 'o'
		|| type == 'x' || type == 'X')
		ft_memset(ret, '0', len);
	ret[len] = '\0';
	return (ft_strjoin(ret, str));
}

static char				*store_hash(char *str, t_flags flags)
{
	int		i;

	i = 0;
	if (flags.spec == 'x' && flags.value != 0)
	{
		if (flags.width <= 2)
			return (ft_strjoin("0x", str));
		if (flags.width > 2 && flags.zero == 0)
		{
			if (flags.presize == 0)
				i = flags.width - ft_numlength_base(flags.value, 16) - 2;
			else
				i = flags.width - flags.presize - 2;
			str[i] = '0';
			str[i + 1] = 'x';
		}
		else if (flags.width > 2 && flags.zero == 1)
		{
			str[i] = '0';
			str[i + 1] = 'x';
		}
	}
	return (str);
}

char					*write_output(char *str, t_flags flags)
{
	int		len;
	int		c;

	len = ft_strlen(str);
	c = (flags.zero > 0) ? '0' : ' ';
	(flags.sign == 1) ? flags.space = 0 : 1;
	(flags.space == 1 && flags.value < 0) ? flags.space = 0 : 1;
	if (flags.integer == 1 && flags.presize >= 0)
		str = store_pre_int(str, flags.presize - len, flags.spec);
	else if (flags.spec == 's' && flags.presize > 0)
		str = ft_strsub(str, 0, flags.presize);
	if (flags.width - flags.presize > 0 && flags.width - len > 0)
		str = store_width(str, flags.width - ft_strlen(str),
		flags.justification, c);
	if ((flags.spec == 'o' || flags.spec == 'x' || flags.spec == 'X') && flags.hash == 1)
		str = store_hash(str, flags);
	return(str);
}
