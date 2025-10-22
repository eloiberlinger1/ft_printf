/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberling <eberling@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:13:30 by eberling          #+#    #+#             */
/*   Updated: 2025/10/22 14:57:32 by eberling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *c, ...)
{
	int i;
	int	vars_count;
	char keys[] = "cspdiuxX%";

	i = 0;
	vars_count = 0;

	while (c[i] != '\0')
	{
		if(c[i] == '%')
			vars_count += ft_contains(c[i + 1], keys);
		i++;
	}

	return 0;
}