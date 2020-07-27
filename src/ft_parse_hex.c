/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:43:03 by amayor            #+#    #+#             */
/*   Updated: 2020/07/27 21:43:03 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flags_hex(char *hex, t_flags flags)
{
	size_t	len;
	int		count;

	count = 0;
	len = ft_strlen(hex);
	if (flags.minus == 1)
		count += ft_utils_print_hex(hex, flags, len);
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
		count += ft_utils_print_hex(hex, flags, len);
	return (count);
}

 int		ft_parser_hex(unsigned int number, inf flag, t_flags s_flags)
 {
	 char	*hex;
	 int	count;

	count = 0;
	if (flags.dot == 0 && n == 0)
	{
		count += ft_utils_print_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_itoa_base((unsigned long long)n, 16);
	if (flag == 1)
		hex = ft_str_tolower(hex);
	count += check_flags_hex(char *hex, t_flags flags);
 }