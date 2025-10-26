/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_ons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:19:52 by pabartoc          #+#    #+#             */
/*   Updated: 2025/10/26 16:35:38 by pabartoc         ###   ########.fr       */
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
