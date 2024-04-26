/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/04/26 21:20:05 by tuchikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, char format)
{
	int	printed_chars;

	if (nbr == 0)
		return (write(1, "0", 1));
	else
	{
		if (0 > ft_put_ptr(nbr, format == 'x'))
			return (-1);
		printed_chars = ft_ptr_len(nbr);
	}
	return (printed_chars);
}
