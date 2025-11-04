/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:13:30 by eberling          #+#    #+#             */
/*   Updated: 2025/11/04 14:05:46 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process(char s, va_list args)
{
	if (s == 'c')
		return (process_char(args));
	else if (s == 's')
		return (process_str(args));
	else if (s == 'd' || s == 'i')
		return (process_int(args));
	else if (s == 'u')
		return (process_uint(args));
	else if (s == '%')
		return (write(1, "%%", 1));
	else if (s == 'p')
		return (process_ptr(args));
	else if (s == 'x')
		return (process_hex(args, 0));
	else if (s == 'X')
		return (process_hex(args, 1));
	else
		return (process_unknown(s));
	return (0);
}


int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		i;
	int		len_tt;
	int		result;

	result = 0;
	i = 0;
	len_tt = 0;
	if (c == NULL)
		return (-1);
	va_start(args, c);
	while (c[i] != '\0')
	{
		if (c[i] == '%' && c[i + 1])
			result = process(c[++i], args);
		else
			result = write(1, &c[i], 1);
		if (result == -1)
			return (-1);
		len_tt += result;
		i++;
	}
	va_end(args);
	return (len_tt);
}

