/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_conflict_fix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:10:53 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/06 17:11:11 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		flags_conflict_fix(t_flags flags)
{
	if (flags.integer == 1 && flags.zero == 1 && flags.presize >= 0)
		flags.zero = 0;
	if (flags.justification == 1 && flags.zero == 1)
		flags.zero = 0;
	if (flags.integer == 0)
		flags.sign = 0;
	if (flags.integer == 1 && flags.sign == 1)
		flags.space = 0;
	if (flags.sign == 1 || (int)flags.value < 0)
		flags.space = 0;
	if (flags.spec == 'c' && (int)flags.value == 0)
		flags.emptychar = 1;
	return (flags);
}
