/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:13:30 by eberling          #+#    #+#             */
/*   Updated: 2025/10/23 12:17:46 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *c, ...)
{
	va_list		args;
	int			 i;
	int			len_tt;

	i = 0;
	len_tt = 0;
	va_start(args, c);
	while (c[i] != '\0')
	{
		if(c[i] == '%')
			len_tt += process(c[++i], args);
		else
			len_tt += write(1, &c[i], 1);
		i++;
	}
	va_end(args);
	return 0;
}