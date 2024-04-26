/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/04/26 21:17:50 by tuchikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_put_ptr(unsigned long long num, int is_lower)
{
	char	c;

	if (num >= 16)
	{
		if (0 > ft_put_ptr(num / 16, is_lower) || 0 > ft_put_ptr(num % 16,
				is_lower))
			return (-1);
	}
	else
	{
		if (num <= 9)
			c = num + '0';
		else
		{
			if (is_lower)
				c = (num - 10 + 'a');
			else
				c = (num - 10 + 'A');
		}
		return (ft_printchar(c));
	}
	return (0);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	printed_chars;

	printed_chars = 0;
	if (0 <= write(1, "0x", 2))
		printed_chars += 2;
	else
		return (-1);
	if (ptr == 0)
	{
		if (0 <= write(1, "0", 1))
			printed_chars++;
		else
			return (-1);
	}
	else
	{
		if (0 > ft_put_ptr(ptr, 1))
			return (-1);
		printed_chars += ft_ptr_len(ptr);
	}
	return (printed_chars);
}
