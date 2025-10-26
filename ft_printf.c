/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:24:04 by pabartoc          #+#    #+#             */
/*   Updated: 2025/10/26 16:35:09 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list args)
{
	int	count;

	if (specifier == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count = 
	else if (specifier == 'd' || specifier == 'i')
		count = 
	else if (specifier == 'u')
		count = 
	else if (specifier == 'x' || specifier == 'X')
		count = 
	else if (specifier == '%')
		count = write(1, "%", 1);
	return (count);
}

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
			counter += handle_specifier(input[++i], args);
		
	}
	
	return (va_end(args), counter);
}
