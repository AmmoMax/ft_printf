/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:37:28 by amayor            #+#    #+#             */
/*   Updated: 2020/07/24 10:37:28 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_parse_string(char *s, va_list ap)
{
	size_t	i;
	size_t	count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (s[i])
	{
		flags = ft_init_flags();
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			i = ft_check_flag(s, i, &flags, ap);
			if (ft_isspec(s[i]))
				count += ft_parser_spec((char)flags.spec, flags, ap);
		}
		else if (s[i] == '%' && s[i + 1] == '%')
		{
			write(1, "%", 1);
			i++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	return (i);
}
