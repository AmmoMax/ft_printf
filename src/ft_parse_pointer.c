/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:52:16 by amayor            #+#    #+#             */
/*   Updated: 2020/07/27 17:52:16 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int			ft_parser_pointer(unsigned long long n, t_flags flags)
{
	char	*addr;
	size_t	len;
	int		count;

	count = 0;
	if (n == 0 && flags.dot == 0)
	{
		count += ft_putstr_len("0x", 2);
		return (count += ft_utils_print_width(flags.width, 0, 1));
	}
	if (n == 0 && flags.dot >= 0)
		flags.width -= 1;
	addr = ft_itoa_base(n, 16);
	addr = ft_str_tolower(addr);
	len = ft_strlen(addr);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.minus == 1)
		count += ft_utils_print_addr(addr, flags, len);
	count += ft_utils_print_width(flags.width, len + 2, 0);
	if (flags.minus == 0)
		count += ft_utils_print_addr(addr, flags, len);
	free(addr);
	return (count);
}

char		ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}