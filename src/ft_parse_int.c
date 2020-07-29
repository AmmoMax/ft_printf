/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:09:32 by amayor            #+#    #+#             */
/*   Updated: 2020/07/29 20:41:18 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flags_int(char *num_str, int tmp, t_flags flags)
{
	size_t	len;
	int		count;

	count = 0;
	len = ft_strlen(num_str);
	if (flags.minus == 1)
		count += ft_utils_print_int(num_str, tmp, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_utils_print_width(flags.width, 0, 0);
	}
	else if (flags.zero == 1 && flags.minus == 1)
	{
		flags.zero = 0;
		count += ft_utils_print_width(flags.width, len, flags.zero);
	}
	else
		count += ft_utils_print_width(flags.width, len, flags.zero);
	if (flags.minus == 0)
		count += ft_utils_print_int(num_str, tmp, flags, len);
	return (count);
}

static int	check_min(char **num_str, int tmp, t_flags flags)
{
	int		count;

	count = 0;
	if (tmp == -2147483648 && flags.zero == 1 && flags.dot < 0)
		count += check_flags_int(*num_str + 1, tmp, flags);
	else
		count += check_flags_int(*num_str, tmp, flags);
	return (count);
}

int			ft_parser_int(int n, t_flags flags)
{
	int		count;
	int		tmp;
	char	*num_str;

	count = 0;
	tmp = n;
	if (flags.dot == 0 && n == 0)
	{
		count += ft_utils_print_width(flags.width, 0, 0);
		return (count);
	}
	if (n < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot < 0)
			ft_putchar('-');
		n *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	num_str = ft_itoa(n);
	count += check_min(&num_str, tmp, flags);
	free(num_str);
	return (count);
}
