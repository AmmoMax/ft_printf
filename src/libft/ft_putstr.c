/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:58:53 by amayor            #+#    #+#             */
/*   Updated: 2020/07/23 22:07:31 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if(s != NULL)
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		
}