/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:16:04 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/13 16:21:28 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*store_space(char *str)
{
	char *tmp;

	tmp = ft_strjoin(" ", str);
	free(str);
	return (tmp);
}
