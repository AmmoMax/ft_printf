/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:43:53 by amayor            #+#    #+#             */
/*   Updated: 2020/07/27 22:43:53 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned(char *num_str, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_utils_print_width(flags.dot - 1, len - 1, 1);
	count += ft_putstr_len(num_str, len);
	return (count);
}

static int	check_flags(char *num_str, t_flags flags)
{
	int		count;
	size_t	len;

	count = 0;
	len = ft_strlen(num_str);
	if (flags.minus == 1)
		count += print_unsigned(num_str, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_utils_print_width(flags.width, 0, 0);
	}
	else
		count += ft_utils_print_width(flags.width, len, flags.zero);
	if (flags.minus == 0)
		count += print_unsigned(num_str, flags, len);
	return (count);
}


int			ft_parser_unsigned(unsigned int num, t_flags flags)
{
	int		count;
	char	*num_str;

	count = 0;
	if (flags.dot == 0 && num == 0)
	{
		count += ft_utils_print_width(flags.width, 0, 0);
		return (count);
	}
	num_str = ft_itoa_base(num, 10);
	count += check_flags(num_str, flags);
	free(num_str);
	return (count);
}
