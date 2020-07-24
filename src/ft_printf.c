/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:33:57 by amayor            #+#    #+#             */
/*   Updated: 2020/07/21 18:33:57 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

// s = "Hello %s! The deadline is in %u days.\n";
int	ft_printf(const char *s, ...)
{
	va_list ap;
	int	count;
	char *str;

	count = 0;
	if (!(str = ft_strdup(s)))
		return (-1);
	va_start(ap, s);
	count += ft_parse_string(str, ap);
	va_end(ap);
	free(str);
	return (count);
}


int main()
{
	char c;
	c = 'A';
	unsigned int nbr = 123;
	ft_printf("Hello %c %s %%3 %c %s %u.\n", c, "Max", 'B', "Alex", nbr);
	return (0);
}