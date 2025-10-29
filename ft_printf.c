/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:24:04 by pabartoc          #+#    #+#             */
/*   Updated: 2025/10/29 04:18:01 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_specifier(char specifier, va_list args)
{
	int	counter;

	if (specifier == 'c')
		counter = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		counter = ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		counter = ft_putptr(va_arg(args, void *), 0);
	else if (specifier == 'd' || specifier == 'i')
		counter = ft_putnbr(va_arg(args, int), 10);
	else if (specifier == 'u')
		counter = 
	else if (specifier == 'x' || specifier == 'X')
		counter = 
	else if (specifier == '%')
		counter = write(1, "%", 1);
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, input);
	i = -1;
	counter = 0;
	while (input[++i] != '\0')
	{
		if (input[i] == '%')
			counter += handle_specifier(input[++i], args);
		else
		{
			write(1, &input[i], 1);
			counter++;
		}
	}
	return (va_end(args), counter);
}
