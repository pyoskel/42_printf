/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_ons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:19:52 by pabartoc          #+#    #+#             */
/*   Updated: 2025/11/02 18:26:38 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	counter;

	counter = (write(1, &c, 1));
	return (counter);
}

int	ft_putstr(char *str)
{
	int	i;
	int	counter;
	int	write_err;

	i = -1;
	counter = 0;
	if (!str)
	{
		write_err = ft_putstr("(null)");
		if (write_err == -1)
			return (-1);
		return (write_err);
	}
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
			return (counter += write(1, PTRNULL, PTRSIZE));
		counter += write(1, "0x", 2);
	}
	if (address >= 16)
		counter += ft_putptr((void *)(address / 16), 1);
	hexadec = HEXALOWER[address % 16];
	counter += write(1, &hexadec, 1);
	return (counter);
}

int	ft_putnbr(int nbr, unsigned int base)
{
	int		counter;
	char	for_dec;

	counter = 0;
	if (nbr == INT_MIN)
		return (counter += write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		counter += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= (int)base)
		counter += ft_putnbr(nbr / base, base);
	for_dec = BASE10[nbr % base];
	counter += write(1, &for_dec, 1);
	return (counter);
}

int	ft_puthex_or_u(unsigned int nbr, char c, unsigned int base)
{
	int		counter;
	char	hexadec;

	counter = 0;
	if (nbr >= base)
		counter += ft_puthex_or_u(nbr / base, c, base);
	if (c == 'X')
		hexadec = HEXAUPPER[nbr % base];
	else
		hexadec = HEXALOWER[nbr % base];
	counter += write(1, &hexadec, 1);
	return (counter);
}

// int main(void) // ft_putchar
// {
// 	ft_printf("%c\n", '9');
// 	printf("%c\n", '9');
// 	ft_putchar('9');
// 	return (0);
// }

// int main(void) // ft_putstr
// {
// 	int count;

// 	count = ft_printf ("Test: %s | counter: %d\n","NULL", count);
// 	printf ("Original: %s | counter: %d\n", "NULL", count);
// 	// printf("hallo %s!\n", "world");
// 	// ft_printf("hallo %s!\n", "world");
// 	return (0);
// }

// int main(void) // ft_putstr mit NULL testen
// {
//     int count_null;
//     char *null_ptr = NULL; // Definiert einen echten Null-Pointer

//     ft_printf("--- Test: %%s mit NULL ---\n");

//     // Testen der ft_printf Funktion
//     // Sie sollte "ft_printf (null)" ausgeben.
//     // Gedruckte Zeichen: "ft_printf " (10) + "(null)" (6) = 16
//     count_null = ft_printf("%s", null_ptr); 
//     ft_printf(" | ft_printf Return-Wert: %d\n", count_null);
    
//     // Vergleich mit dem Standard-printf (optional)
//     int std_count_null = printf("%s", null_ptr);
//     printf(" | Original printf Return-Wert: %d\n", std_count_null);
    
//     return (0);
// }

// int main(void) // ft_putptr
// {
//     int count;
//     void *ptr = (void *)0xDEADBEEF; // Ein Beispiel-Pointer

//     // Test
//     count = ft_printf("Test:	  %p | %p\n", ptr, NULL);
//     printf("Original: %p | %p | (count: %d)\n", ptr, NULL, count);

//     return 0;
// }

// int	main(void) // ft_putnbr
// {
// 	printf("%d\n", INT_MIN);
// 	ft_printf("%d\n", INT_MIN);
// 	return (0);
// }

// int	main(void)	// ft_puthex_or_u
// {
// 	int				number1 = 255;
// 	int				number2 = 0;
// 	unsigned int	number3 = 4294967295;

// 	printf("Lowercase hex (x): %x\n", number1);
// 	ft_printf("Lowercase hex (x): %x\n\n", number1); // Erwartet: "ff"

// 	printf("Uppercase hex (X): %X\n", number1);
// 	ft_printf("Uppercase hex (X): %X\n\n", number1); // Erwartet: "FF"

// 	printf("Hex von 0: %x\n", number2);
// 	ft_printf("Hex von 0: %x\n\n", number2); // Erwartet: "0"

// 	// Erwartet: "ffffffff"
// 	printf("Hex von 4294967295 (UINT_MAX): %x\n", number3);
// 	ft_printf("Hex von 4294967295 (UINT_MAX): %x\n", number3);
// 	return (0);
// }
