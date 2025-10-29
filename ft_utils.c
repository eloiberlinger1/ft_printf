/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:25:32 by eberling          #+#    #+#             */
/*   Updated: 2025/10/28 17:18:51 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// int	pointer_entrypoint()
// {
	
// }

int	process(char s, va_list args)
{
	void	*value;

	if (s == 'c')
		return (process_char(va_arg(args, int)));
	else if (s == 's')
		return (process_str(args));
	else if (s == 'd' || s == 'i' || s == 'u')
		return (process_int(va_arg(args, int)));
	else if (s == '%')
		return (process_char('%'));
	else if (s == 'p')
	{
		value = va_arg(args, void *);
		if (value == NULL)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		return (process_hex((uintptr_t)(value), 2));
	}
	else if (s == 'x')
	{
		value = va_arg(args, void *);
		return (process_hex((uintptr_t)(value), 0));
	}
	else if (s == 'X')
	{
		value = va_arg(args, void *);
		return (process_hex((uintptr_t)(value), 1));
	}
	return (0);
}
