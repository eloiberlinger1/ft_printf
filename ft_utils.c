/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:25:32 by eberling          #+#    #+#             */
/*   Updated: 2025/10/29 18:06:15 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process(char s, va_list args)
{
	if (s == 'c')
		return (process_char(args));
	else if (s == 's')
		return (process_str(args));
	else if (s == 'd' || s == 'i' || s == 'u')
		return (process_int(args));
	else if (s == '%')
		return (write(1, "%%", 1));
	else if (s == 'p')
		return (process_hex(args, 2));
	else if (s == 'x')
		return (process_hex(args, 0));
	else if (s == 'X')
		return (process_hex(args, 1));
	return (-1);
}
