/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:29:18 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 17:59:32 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

char	*func_char(va_list ap, char *hold)
{
	va_list apc;

	va_copy(apc, ap);
	if (va_arg(apc, int) == 0)
		return (ft_strjoin("", " "));
	hold = ft_memset(hold, va_arg(ap++, int), 1);
	return (hold);
}
