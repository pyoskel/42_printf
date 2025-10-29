/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_ons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:19:52 by pabartoc          #+#    #+#             */
/*   Updated: 2025/10/29 04:19:14 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i] != '\0')
		counter += ft_putchar(str[i]);
	return (counter);
}

int	ft_putptr(void *ptr, int flag)
{
	unsigned long	address;
	int				counter;
	char			hexadec;

	address = (unsigned long)ptr;
	counter = 0;
	if (flag == 0)
	{
		if (!ptr)
		{
			counter += (write(1, PTRNULL, PTRSIZE));
			return (counter);
		}
		counter += write(1, "0x", 2);
	}
	if (address >= 16)
		counter += ft_putptr((void *)(address / 16), 1);
	hexadec = HEXALOWER[address % 16];
	counter += write(1, &hexadec, 1);
	return (counter);
}

