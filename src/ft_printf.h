/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:23:17 by amayor            #+#    #+#             */
/*   Updated: 2020/07/28 22:55:24 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_flags
{
	int				spec;
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
int			ft_parser_dot(char *str, int i, t_flags *flags, va_list ap);
t_flags		ft_parser_minus(t_flags flags);
t_flags		ft_parser_width(t_flags flags, va_list ap);
t_flags		ft_parser_digit(char c, t_flags flags);
int			ft_parser_spec(int c, t_flags, va_list ap);
int			ft_parser_char(char c, t_flags flags);
int			ft_utils_print_width(int width, int len, int zero);
int			ft_utils_print_str(char *str, t_flags flags, int len);
int			ft_utils_print_int(char *substr, int tmp, t_flags flags, size_t len);
int			ft_utils_print_hex(char *hex, t_flags flags, size_t len);
int			ft_parser_str(char *str, t_flags flags);
int			ft_parser_int(int n, t_flags flags);
int			ft_parser_pointer(unsigned long long n, t_flags flags);
int			ft_parser_hex(unsigned int number, int flag, t_flags s_flags);
int			ft_parser_unsigned(unsigned int num, t_flags flags);
char		ft_str_tolower(char *str);
int			ft_utils_print_addr(char *addr, t_flags s_flags, size_t len);
int			ft_print_percent(t_flags flags);

#endif