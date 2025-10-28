/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 09:59:48 by eberling          #+#    #+#             */
/*   Updated: 2025/10/28 15:18:35 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_char_size(long long n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		c++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static int	ifzero(long long nbr)
{
	if(nbr == 0)
	{
		ft_putchar_fd('0', 1);
		if (write(1, '0', 1) != 1)
			return (-1);
		return (1);
	}
	return (0);
}

int	process_hex(uintptr_t nbr, int maj)
{
	size_t		i;
	int			ret;
	long long	longnbr;
	char		base[17];
	char		buffer[11];

	i = 0;
	ft_strlcpy(base, "0123456789abcdef", 16);
	if (maj == 1)
		ft_strlcpy(base, "0123456789ABCDEF", 16);
	longnbr = (int)nbr;
	if (ifzero(longnbr) == -1)
		return (-1);
	while (longnbr > 0)
	{
		buffer[i++] = base[longnbr % 16];
		longnbr /= 16;
	}
	while (i-- > 0)
		ft_putchar_fd(buffer[i], 1);
	ret = get_char_size(longnbr);
	return (ret);
}
