/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:25:32 by eberling          #+#    #+#             */
/*   Updated: 2025/10/28 15:18:56 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_char(int value)
{
	return (write(1, &value, 1));
}

static int	process_str(va_list args)
{
	char	*value;
	int		i;

	i = 0;
	value = va_arg(args, char *);
	while (value[i])
		write(1, &value[i++], 1);
	return (i);
}

static int	process_int(int value)
{
	char	*temp;
	int		ret;

	temp = ft_itoa(value);
	if (!temp)
		return (0);
	ft_putstr_fd(temp, 1);
	ret = ft_strlen(temp);
	free(temp);
	return (ret);
}

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
		ft_putstr_fd("0x", 1);
		return (process_hex((uintptr_t)(value), 0));
	}
	else if (s == 'x')
	{
		value = va_arg(args, void *);
		return (process_hex((uintptr_t)(value), 0));
	}
	else if (s == 'x')
	{
		value = va_arg(args, void *);
		return (process_hex((uintptr_t)(value), 1));
	}
	return (0);
}
