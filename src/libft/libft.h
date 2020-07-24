/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:00:12 by amayor            #+#    #+#             */
/*   Updated: 2020/07/24 22:46:30 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *s);
int		ft_isalpha(int c);
char	*ft_itoa_base(unsigned long long number, int base);
void	ft_putnbr(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);

#endif