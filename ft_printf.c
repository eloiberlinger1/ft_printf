/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:13:30 by eberling          #+#    #+#             */
/*   Updated: 2025/10/28 16:03:49 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		i;
	int		len_tt;
	int 	result;

	result = 0;
	i = 0;
	len_tt = 0;
	if (c == NULL)
		return (0);
	va_start(args, c);
	while (c[i] != '\0')
	{
		if (c[i] == '%')
			len_tt = process(c[++i], args);
		else
			len_tt += write(1, &c[i], 1);
		if (len_tt <= 0)
			return (-1);
		result += len_tt;
		len_tt = 0;
		i++;
	}
	va_end(args);
	return (0);
}
