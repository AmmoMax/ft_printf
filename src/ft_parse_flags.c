/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 22:05:31 by amayor            #+#    #+#             */
/*   Updated: 2020/07/29 20:44:28 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parser_dot(char *str, int i, t_flags *flags, va_list ap)
{
	if (str[++i] == '*')
	{
		flags->dot = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
			flags->dot = (flags->dot * 10) + (str[i++] - '0');
	}
	return (i);
}

t_flags		ft_parser_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_parser_width(t_flags flags, va_list ap)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_flags		ft_parser_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}
