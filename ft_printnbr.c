/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:00:31 by eberling          #+#    #+#             */
/*   Updated: 2025/10/30 12:23:55 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_int(va_list args)
{
	char	*temp;
	int		ret;
	int		i;

	i = va_arg(args, int);
	if (!i)
		return (-1);
	temp = ft_itoa(i);
	if (!temp)
		return (-1);
	ret = ft_putstr_fd(temp, 1);
	if (ret == -1)
		return (-1);
	free(temp);
	return (ret);
}
