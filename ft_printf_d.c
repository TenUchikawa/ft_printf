/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:03 by tuchikaw          #+#    #+#             */
/*   Updated: 2024/05/01 16:24:44 by tuchikaw         ###   ########.fr       */
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

int	ft_printnbr(int nbr)
{
	int		printed_chars;
	char	*str;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	printed_chars = ft_printstr(str);
	free(str);
	return (printed_chars);
}
