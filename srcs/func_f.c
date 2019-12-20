/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:46:23 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 17:56:46 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_f(char *hold, int type, va_list ap, t_flags flags)
{
	if (type == 5)
		return (hold = ft_ftoa((long double)va_arg(ap++, long double),
		flags.presize, flags.hash));
	else
		return (ft_ftoa((double)va_arg(ap++, double),
		flags.presize, flags.hash));
}
