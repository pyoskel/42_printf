/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:24:04 by pabartoc          #+#    #+#             */
/*   Updated: 2025/11/13 21:10:15 by pabartoc         ###   ########.fr       */
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
		counter = ft_puthex_or_u(va_arg(args, unsigned int), specifier, 10);
	else if (specifier == 'x' || specifier == 'X')
		counter = ft_puthex_or_u(va_arg(args, unsigned int), specifier, 16);
	else if (specifier == '%')
		counter = write(1, "%", 1);
	else
		return (-1);
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, input);
	i = -1;
	counter = 0;
	while (input[++i] != '\0')
	{
		if (input[i] == '%')
			counter += handle_specifier(input[++i], args);
		else
		{
			counter += write(1, &input[i], 1);
			if (counter == -1)
				return (-1);
		}
	}
	return (va_end(args), counter);
}
