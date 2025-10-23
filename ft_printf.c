/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:24:04 by pabartoc          #+#    #+#             */
/*   Updated: 2025/10/23 06:24:30 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, input);
	i = -1;
	counter = 0;
	while (input != '\0')
	{
		if (input[++i] == '%')
			counter += handle_specifier(input[++1], args);
		
	}
	
	return (va_end(args), counter);
}
