/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:05:07 by dboire            #+#    #+#             */
/*   Updated: 2023/11/17 14:26:57 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(int c, size_t len);
int	ft_putstr(const char *str, int len);
int	ft_switch(const char *s, size_t i, va_list args, int len);
int	ft_putnbr(int nb, int len);
int	ft_put_unsigned_nbr(unsigned int nb, int len);
int	ft_printf(const char *s, ...);
int	ft_puthexa_nbr(unsigned int nb, int len);
int	ft_putchar_base_lower(int c, size_t len);
int	ft_putchar_base_upper(int c, size_t len);
int	ft_puthexa_nbr_upper(unsigned int nb, int len);
int	ft_puthexa_nbr_lower(unsigned int nb, int len);
int	ft_puthexa_pointer(unsigned long long int nb, int len);
int	ft_pointer(unsigned long long int nb, int len);

#endif
