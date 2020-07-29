/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:00:12 by amayor            #+#    #+#             */
/*   Updated: 2020/07/29 21:05:40 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int c);
char	*ft_itoa_base(unsigned long long number, int base);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_putchar(char c);
int		ft_putstr_len(char *s, int len);
char	*ft_itoa(int n);
int		ft_tolower(int c);

#endif
