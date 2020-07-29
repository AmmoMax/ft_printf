/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 20:38:12 by amayor            #+#    #+#             */
/*   Updated: 2020/07/29 21:06:19 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags	flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.dot = -1;
	flags.width = 0;
	flags.spec = 0;
	flags.star = 0;
	return (flags);
}
