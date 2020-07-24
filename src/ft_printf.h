/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:23:17 by amayor            #+#    #+#             */
/*   Updated: 2020/07/24 22:58:29 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int 		ft_printf(const char *s, ...);
size_t		ft_parse_string(char *s, va_list ap);
t_flags		ft_init_flags(void);
int			ft_check_flag(char *str, int i, t_flags *flags, va_list ap);
int			ft_isspec(int c);
int			ft_isflag(int c);

#endif