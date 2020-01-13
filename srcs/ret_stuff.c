/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:59:54 by tmaarela          #+#    #+#             */
/*   Updated: 2020/01/13 18:06:51 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Simple function to make code cleaner.
** Free arguments 1 and 2 and return arg 3.
*/

#include "../ft_printf.h"

char				*ret_stuff(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	return (s3);
}
