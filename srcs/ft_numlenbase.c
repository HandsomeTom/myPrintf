/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:59:54 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/02 17:03:05 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int	ft_numlenbase(int num, int base)
{
	int ret;

	ret = 1;
	if (num < 0)
		ret++;
	while (num / base != 0)
	{
		num /= base;
		ret++;
	}
	return (ret);
}
