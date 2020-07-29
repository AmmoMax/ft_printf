/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:33:57 by amayor            #+#    #+#             */
/*   Updated: 2020/07/29 20:35:25 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	char	*str;

	count = 0;
	if (!(str = ft_strdup(s)))
		return (-1);
	va_start(ap, s);
	count += ft_parse_string(str, ap);
	va_end(ap);
	free(str);
	return (count);
}
