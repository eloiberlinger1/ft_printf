/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 09:59:48 by eberling          #+#    #+#             */
/*   Updated: 2025/10/29 09:01:18 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ifzero(uintptr_t nbr)
// {
	
// }

int	process_hex(uintptr_t nbr, int maj)
{
	size_t		i;
	int			ret;
	uintptr_t	uninbr;
	char		*base;
	char		buffer[17];

	// initialize the base
	base = "0123456789abcdef";
	if (maj == 1)
		base = "0123456789ABCDEF";


	ret = 0;
	// display 0x
	if (maj == 2) 
        ret += write(1, "0x", 2);


	// handle zero case
	if(nbr == 0)
	{
		if (ft_putchar_fd('0', 1) != 1)
			return (-1);
		ret++;
		return (ret);
	}

	// Conversion et Remplissage du buffer
	i = 0;
	uninbr = nbr;
	while (uninbr > 0)
	{
		buffer[i++] = base[uninbr % 16];
		uninbr /= 16;
	}

	// Affichage (le nombre de chars imprimés = i)
	ret += i;
	while (i-- > 0)
		if (ft_putchar_fd(buffer[i], 1) != 1)
			return (-1);
	return (ret);
}
