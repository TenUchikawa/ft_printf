/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/04/22 04:17:52 by tuchikaw         ###   ########.fr       */
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

void	ft_put_ptr(unsigned long long num, int is_lower)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16, is_lower);
		ft_put_ptr(num % 16, is_lower);
	}
	else
	{
		if (num <= 9)
			ft_printchar((num + '0'));
		else
		{
			if (is_lower)
				ft_printchar((num - 10 + 'a'));
			else
				ft_printchar((num - 10 + 'A'));
		}
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
		ft_put_ptr(ptr, 1);
		printed_chars += ft_ptr_len(ptr);
	}
	return (printed_chars);
}
