/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/04/26 22:28:02 by tuchikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (format == 'u')
		printed_chars += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed_chars += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		printed_chars += ft_printpercent();
	if (printed_chars < 0)
		return (-1);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed_chars;
	int		tmp;
	va_list	args;

	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = ft_formats(args, format[++i]);
		}
		else
			tmp = ft_printchar(format[i]);
		if (tmp >= 0)
			printed_chars += tmp;
		else
			return (-1);
		i++;
	}
	return (printed_chars);
}

// int	main(void)
// {
// 	int res = ft_printf("Hello, %u\n", -1);
// 	ft_printf("res %d\n", res);

// 	return (0);
// }