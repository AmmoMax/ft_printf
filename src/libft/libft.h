/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:00:12 by amayor            #+#    #+#             */
/*   Updated: 2020/07/29 14:26:30 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// void	ft_putstr(char *s);
int		ft_isalpha(int c);
char	*ft_itoa_base(unsigned long long number, int base);
// void	ft_putnbr(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_putchar(char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_putstr_len(char *s, int len);
char	*ft_itoa(int n);
int		ft_tolower(int c);

#endif