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

int	ft_isspec(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'i') || (c == 'd') ||
		(c == 'x') || (c == 'X') || (c == 'u') || (c == 'p') || (c == '%'));
}

int ft_isflag(int c)
{
	return ((c == '-') || (c == '*') || (c == '.') || (c == '0') || (c == ' '));
}

int	ft_check_flag(char *str, int i, t_flags *flags, va_list ap)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspec(str[i]) && !ft_isflag(str[i]))
			break;
		if (str[i] == '-')
			*flags = ft_parser_minus(*flags);
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_parser_dot(str, i, flags, ap);
		if (str[i] == '*')
			*flags = ft_parser_width(*flags, ap);
		if (ft_isdigit(str[i]))
			*flags = ft_parser_digit(str[i], *flags);
		if (ft_isspec(str[i]))
		{
			flags->spec = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_print_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putchar('%');
	count += ft_utils_print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putchar('%');
	return (count);
}

int	ft_parser_spec(int c, t_flags flags, va_list ap)
{
	int count;

	count = 0;
	if (c == 'c')
		count += ft_parser_char(va_arg(ap, int), flags);
	else if (c == 's')
		count += ft_parser_str(va_arg(ap, char *), flags);
	else if (c == 'd' || c == 'i')
		count += ft_parser_int(va_arg(ap, int), flags);
	else if (c == 'p')
		count += ft_parser_pointer(va_arg(ap, unsigned long long int), flags);
	else if (c =='x')
		count += ft_parser_hex(va_arg(ap, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_parser_hex(va_arg(ap, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_parser_unsigned(va_arg(ap, unsigned int), flags);
	else if (c == '%')
		count += ft_print_percent(flags);
	return (count);
}