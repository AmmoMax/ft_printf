/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:52:56 by amayor            #+#    #+#             */
/*   Updated: 2020/07/24 14:52:56 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_check_spec(char * str, int i,t_flags *flags, va_list ap)
{
	char			c_type;
	char			*s_type;
	unsigned int	u_type;

	if (c == 'c')
	{
		c_type = va_arg(ap, int);
		write(1, &c_type, 1);
		return (1);
	}
	if (c == 's')
	{
		s_type = va_arg(ap, char *);
		ft_putstr(s_type);
		return (1);
	}
	if (c == 'u')
	{
		u_type = va_arg(ap, unsigned int);
		ft_putstr(ft_itoa_base(u_type, 10));
		return (1);
	}
	return (0);
}

int	ft_isspec(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'i') || (c == 'd') ||
		(c == 'x') || (c == 'X') || (c == 'u') || (c == 'p') || (c == '%'));
}

int ft_isflag(int c)
{
	return ((c == '-') || (c == '*') || (c == '.') || (c == '0') || (c == ' '))
}

int	ft_check_flag(char *str, int i, t_flags *flags, va_list ap)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspec(str[i]) && !ft_isflag(str[i]))
			break;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
	}
}
