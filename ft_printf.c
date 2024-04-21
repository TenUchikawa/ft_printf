/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/04/19 23:09:18 by tuchikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_printstr(char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'));
		else
			ft_printchar((num - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	printed_chars;

	printed_chars = 0;
	printed_chars += write(1, "0x", 2);
	if (ptr == 0)
		printed_chars += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		printed_chars += ft_ptr_len(ptr);
	}
	return (printed_chars);
}

int	ft_printnbr(int nbr)
{
	int		printed_chars;
	char	*str;

	str = ft_itoa(nbr);
	printed_chars = ft_printstr(str);
	free(str);
	return (printed_chars);
}

int	ft_formats(va_list args, const char format)
{
	int	printed_chars;

	printed_chars = 0;
	if (format == 'c')
		printed_chars += ft_printchar(va_arg(args, int));
	else if (format == 's')
		printed_chars += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		printed_chars += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printed_chars += ft_printnbr(va_arg(args, int));
	// else if (format == 'u')
	// 	printed_chars += ft_print_unsigned(va_arg(args, unsigned int));
	// else if (format == 'x' || format == 'X')
	// 	printed_chars += ft_print_hex(va_arg(args, unsigned int), format);
	// else if (format == '%')
	// 	printed_chars += ft_printpercent();
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed_chars;
	va_list	args;

	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			printed_chars += ft_formats(args, format[++i]);
		else
			printed_chars += ft_printchar(format[i]);
		i++;
	}
	return (printed_chars);
}

// int	main(void)
// {
// 	int res = ft_printf("Hello, %d\n", -2147483648);
// 	ft_printf("res %d\n", res);

// 	return (0);
// }