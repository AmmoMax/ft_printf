/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 20:38:12 by amayor            #+#    #+#             */
/*   Updated: 2020/07/24 20:38:12 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags	flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.type;
	flags.asterisk = 0;
	return (flags);
}