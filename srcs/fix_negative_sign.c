/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_negative_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:05:04 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/02 17:29:22 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A stupid function to fix '-' negative sign's position in the string
** after applying width and precision.
*/

#include "../ft_printf.h"

char			*fix_negative_sign(char *str, t_flags flags)
{
	int		i;
	int		j;
	int		sign;

	i = 0;
	j = 0;
	sign = 0;
	if (str[0] != ' ' && str[0] != '0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = 1;
			str[i] = '0';
		}
		i++;
		j++;
	}
	i = 0;
	while (str[i] == ' ')
		i++;
	if (flags.presize > ft_numlenbase(flags.value, 10) && sign == 1)
		str = ft_strjoin(ft_strjoin(ft_strsub(str, 0, i), "-"), ft_strsub(str, i + 1, j - i));
	else if (sign == 1)
		str[i] = '-';
	return (str);
}
