/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:40:13 by amayor            #+#    #+#             */
/*   Updated: 2020/07/27 14:40:13 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_utils_print_width(int width, int len, int zero)
{
	int	count;

	count = 0;
	while(width - len > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		count++;
	}
	return (count);
}

int		ft_utils_print_str(char *str, t_flags flags, int len)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_utils_print_width(flags.dot, len, 0); // флаг 0 не работает со строкой, печатаем пробелы
		count += ft_putstr_len(str, flags.dot);
	}
	else
		count = ft_putstr_len(str, len);
	return (count);
}

int		ft_utils_print_int(char *substr, int tmp, t_flags flags, size_t len)
{
	int count;

	count = 0;
	if (tmp < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_utils_print_width(flags.dot - 1, len - 1, 1); // непонятные аргументы, зачем так?
	count += ft_putstr_len(substr, len);
	return (count);
}

int		ft_utils_print_addr(char *addr, t_flags flags, size_t len)
{
	int	count;

	count = 0;
	count += ft_putstr_len("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_utils_print_width(flags.dot, len, 1);
		count += ft_putstr_len(addr, flags.dot);
	}
	else
		count += ft_putstr_len(addr, len);
	return (count);
}

int		ft_utils_print_hex(char *hex, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_utils_print_width(flags.dot - 1, len - 1, 1);
	count += ft_putstr_len(hex, len);
	return (count);
}