/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:11:03 by amayor            #+#    #+#             */
/*   Updated: 2020/07/27 14:11:03 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_char(char c, t_flags flags)
{
	int count;

	count = 0;
	if(flags.minus == 1)
		ft_putstr(c);
	count = ft_utils_print_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}

int	ft_parser_str(char *str, t_flags flags)
{
	int count;
	int len;
	char *substr;

	count = 0;
	if(!str)
		str = "(null)";
	len = ft_strlen(str);
	substr = ft_substr(str, 0, len); // почему не strdup?
	if (flags.dot >= 0 && (int)flags.dot > len) // посмотреть вывод оригинального printf
		flags.dot = len;
	if (flags.minus == 1)
		count += ft_utils_print_str(substr, flags, len);
	if (flags.dot >= 0)
		count += ft_utils_print_width(flags.width, flags.dot, 0);
	else
		count += ft_utils_print_width(flags.width, len, 0);
	if (flags.minus == 0)
		count += ft_utils_print_str(substr, flags, len);
	free(substr);
	return (count);
}
