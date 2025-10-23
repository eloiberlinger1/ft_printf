/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:13:30 by eberling          #+#    #+#             */
/*   Updated: 2025/10/23 12:01:03 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *c, ...)
{
	va_list	args;
	int		 i;
	int		len_tt;
	char keys[] = "cspdiuxX%";

	i = 0;
	len_tt = 0;
	while (c[i] != '\0')
	{
		if(c[i] == '%')
			len_tt += ft_process(c[i++], args);
		i++;
	}

	va_end(args);

	return 0;
}