/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:15:08 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 17:54:34 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_flags
{
	int			justification;
	int			sign;
	int			hash;
	int			zero;
	int			space;
	int			width;
	int			presize;
	int			skip;
	int			str_len;
	int			spec;
	int			length;
	int			integer;
	long long	value;
}					t_flags;

int					ft_printf(const char *restrict format, ...);
t_flags				store_flags(char *str);
t_flags				store_length_spec(t_flags flags, char *str, va_list ap);
char				*store_data(va_list ap, t_flags flags);
void				write_output(char *str, t_flags flags);

char				*func_d(char *hold, int type, va_list ap);
char				*func_o(char *hold, int type, va_list ap);
char				*func_x(char *hold, int type, va_list ap);
char				*func_capitalx(char *hold, int type, va_list ap);
char				*func_char(va_list ap, char *hold);
char				*func_u(char *hold, int type, va_list ap);
char				*func_f(char *str, int type, va_list ap, t_flags flags);

#endif
