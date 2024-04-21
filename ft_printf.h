/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:07:55 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/04/19 23:14:00 by tuchikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
// int		ft_print_unsigned(unsigned int n);
// int		ft_print_hex(unsigned int num, const char format);
// int		ft_printpercent(void);

// int		ft_putstr(char *str);
char	*ft_itoa(int n);
// char	*ft_uitoa(unsigned int n);
// int		ft_num_len(unsigned int num);
// void	ft_put_hex(unsigned int num, const char format);
// int		ft_hex_len(unsigned int num);

#endif
