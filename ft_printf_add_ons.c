/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_ons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:19:52 by pabartoc          #+#    #+#             */
/*   Updated: 2025/10/26 16:52:01 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i] != '\0')
		count += ft_putchar(str[i]);
	return (count);
}

int	ft_putptr(void *ptr, int flag)
{
	unsigned long	address;
	int				count;
	char			hexadec;

	address = (unsigned long)ptr;
	count = 0;
	if (flag == 0)
	{
		if (!ptr)
		{
			count += (write(1, PTRNULL, PTRSIZE));
			return (count);
		}
		count += write(1, "0x", 2);
	}
	if (address >= 16)
		count += ft_putptr((void *)(address / 16), 1);
	hexadec = HEXALOWER[address % 16];
	count += write(1, &hexadec, 1);
	return (count);
}
