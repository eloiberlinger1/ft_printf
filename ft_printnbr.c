/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:00:31 by eberling          #+#    #+#             */
/*   Updated: 2025/10/28 16:01:43 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_int(int value)
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