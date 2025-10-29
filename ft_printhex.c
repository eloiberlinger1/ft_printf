/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 09:59:48 by eberling          #+#    #+#             */
/*   Updated: 2025/10/29 16:53:37 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex(uintptr_t uninbr, int *ret, char *base)
{
	int		i;
	char	buffer[17];

	i = 0;
	while (uninbr > 0)
	{
		buffer[i++] = base[uninbr % 16];
		uninbr /= 16;
	}
	*ret += i;
	while (i-- > 0)
		if (ft_putchar_fd(buffer[i], 1) != 1)
			return (-1);
	return (*ret);
}

/*
format 0 = x
format 1 = X
format 2 = p
*/
int	process_hex(uintptr_t nbr, int format)
{
	int			ret;
	char		*base;

	base = "0123456789abcdef";
	if (format == 1)
		base = "0123456789ABCDEF";
	ret = 0;
	if (format == 2) 
        ret += write(1, "0x", 2);
	if(nbr == 0)
	{
		if (ft_putchar_fd('0', 1) != 1)
			return (-1);
		ret++;
		return (ret);
	}
	if(puthex(nbr, &ret, base) == -1)
		return (-1);
	return (ret);
}
