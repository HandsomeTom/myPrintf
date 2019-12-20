/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:40:05 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 18:23:31 by tmaarela         ###   ########.fr       */
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

static char				*store_pre_int(char *str, int len, int type, int hash)
{
	char	*ret;

	if (len <= 0)
		return (str);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	if ((type == 'd' || type == 'i' || type == 'u' || type == 'o') || hash == 0)
		ft_memset(ret, '0', len);
	ret[len] = '\0';
	return (ft_strjoin(ret, str));
}

char					*write_output(char *str, t_flags flags)
{
	int		len;
	int		c;

	len = ft_strlen(str);
	c = (flags.zero && flags.presize > 0) ? '0' : ' ';
	(flags.sign == 1) ? flags.space = 0 : 1;
	(flags.space == 1 && flags.value < 0) ? flags.space = 0 : 1;
	(flags.integer == 1) ? str = store_pre_int(str, flags.presize - len,
	flags.spec, flags.hash) : NULL;
	if (flags.width - flags.presize > 0)
		str = store_width(str, flags.width - ft_strlen(str),
		flags.justification, c);
	return(str);
}
