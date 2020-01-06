/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:46:23 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/06 18:17:57 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*func_f(int type, va_list ap, t_flags flags)
{
	if (type == 5)
		return (ft_ftoa((long double)va_arg(ap++, long double),
		flags.presize, flags.hash));
	else
		return (ft_ftoa((double)va_arg(ap++, double),
		flags.presize, flags.hash));
}
