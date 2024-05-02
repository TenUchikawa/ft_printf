/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/05/01 16:25:28 by tuchikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (0 > ft_put_hex(ptr, 1))
			return (-1);
		printed_chars += ft_hex_len(ptr);
	}
	return (printed_chars);
}
