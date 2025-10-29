/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:01:21 by eberling          #+#    #+#             */
/*   Updated: 2025/10/29 17:10:55 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	process_char(va_list args)
{
	int	c;
	c = va_arg(args, int);
	if (!c)
		return (-1);
	if (c == 0)
		return(write(1, "\0", 1));
	return (write(1, &c, 1));
}

int	process_str(va_list args)
{
	char	*value;

	value = va_arg(args, char *);
	if (!value)
		return (0);
	return (ft_putstr_fd(value, 1));
}


