/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:25:32 by eberling          #+#    #+#             */
/*   Updated: 2025/10/26 09:40:03 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_char(va_list args)
{
	char	value;

	value = (char)va_arg(args, int);
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
	char 	*ret;
	
	ret = ft_itoa(value);
	if(!ret)
		return (0);
	ft_putstr_fd(ret, 1);
	free(ret);
	return (1);
}

int	process(char s, va_list args)
{
	//char keys[] = "cspdiuxX%";

	if (s == 'c')
		return (process_char(args));
	else if(s == 's')
		return (process_str(args));
	else if(s == 'd' || s == 'i' || s == 'u')
		return (process_int(va_arg(args, int)));
	return (0);
}