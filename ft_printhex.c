/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 09:59:48 by eberling          #+#    #+#             */
/*   Updated: 2025/11/04 09:55:01 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex(uintptr_t uninbr, char *base)
{
	int		i;
	int		result;
	char	buffer[17];

	i = 0;
	result = 0;
	if (uninbr == 0)
	{
		if (ft_putchar_fd('0', 1) == -1)
			return (-1);
		return (1);
	}
	while (uninbr > 0)
	{
		buffer[i++] = base[uninbr % 16];
		uninbr /= 16;
	}
	while (i-- > 0)
	{
		if (ft_putchar_fd(buffer[i], 1) == -1)
			return (-1);
		result++;
	}
	return (result);
}

int	handle_null(void)
{
	int	result;

	result = 0;
	result = ft_putstr_fd("(nil)", 1);
	if (result == -1)
		return (-1);
	return (result);
}
/*
format 0 = x
format 1 = X
format 2 = p
*/
int	process_hex(va_list arg, int format)
{
	int				ret;
	char			*base;
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(arg, unsigned int);
	ret = 0;
	if (!nbr)
		return (handle_null());
	base = "0123456789abcdef";
	if (format == 1)
		base = "0123456789ABCDEF";
	if (nbr == 0)
	{
		if (ft_putchar_fd('0', 1) == -1)
			return (-1);
		return (1);
	}
	ret += puthex(nbr, base);
	return (ret);
}

int	process_ptr(va_list arg)
{
	int				ret;
	char			*base;
	uintptr_t		nbr;
	
	base = "0123456789abcdef";
	ret = 0;
	nbr = (uintptr_t)va_arg(arg, void *);
	if (!nbr)
		return (handle_null());
	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	if (nbr == 0)
	{
		if (ft_putchar_fd('0', 1) == -1)
			return (-1);
		return (1);
	}
	ret += puthex(nbr, base);
	return (ret);

}