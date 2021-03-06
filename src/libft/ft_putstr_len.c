/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:56:17 by amayor            #+#    #+#             */
/*   Updated: 2020/07/29 21:04:17 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_len(char *s, int len)
{
	int	i;

	i = 0;
	if (s != NULL)
		while (s[i] && i < len)
			ft_putchar(s[i++]);
	return (i);
}
