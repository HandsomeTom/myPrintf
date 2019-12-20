/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:10:40 by tmaarela          #+#    #+#             */
/*   Updated: 2019/10/18 17:30:01 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t c;

	c = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (*str != '\0' && len > 0)
	{
		while (to_find[c] != '\0' && to_find[c] == str[c] && len - c > 0)
			c++;
		if (to_find[c] == '\0')
			return ((char *)str);
		str++;
		len--;
		c = 0;
	}
	return (0);
}
