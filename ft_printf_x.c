/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/05/01 16:25:08 by tuchikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long long num)
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

int	ft_put_hex(unsigned long long num, int is_lower)
{
	char	c;

	if (num >= 16)
	{
		if (0 > ft_put_hex(num / 16, is_lower) || 0 > ft_put_hex(num % 16,
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

int	ft_print_hex(unsigned int nbr, char format)
{
	int	printed_chars;

	if (nbr == 0)
		return (write(1, "0", 1));
	else
	{
		if (0 > ft_put_hex(nbr, format == 'x'))
			return (-1);
		printed_chars = ft_hex_len(nbr);
	}
	return (printed_chars);
}
