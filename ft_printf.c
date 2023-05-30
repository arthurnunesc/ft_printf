/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:31:44 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/31 00:09:32 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	int				n_printed_chars;
	char			*s;

	n_printed_chars = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				n_printed_chars++;
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s, 1);
				n_printed_chars += ft_strlen(s);
			}
			else if (format[i + 1] == 'p')
				;
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				s = ft_itoa(va_arg(args, int));
				if (s == NULL)
					return (-1);
				ft_putstr_fd(s, 1);
				n_printed_chars += ft_strlen(s);
				free(s);
			}
			else if (format[i + 1] == 'u')
			{
				s = ft_utoa(va_arg(args, unsigned int));
				if (s == NULL)
					return (-1);
				ft_putstr_fd(s, 1);
				n_printed_chars += ft_strlen(s);
				free(s);
			}
			else if (format[i + 1] == 'x')
			{
				s = ft_btoa(va_arg(args, int), "0123456789abcdef");
				if (s == NULL)
					return (-1);
				ft_putstr_fd(s, 1);
				n_printed_chars += ft_strlen(s);
				free(s);
			}
			else if (format[i + 1] == 'X')
			{
				s = ft_btoa(va_arg(args, int), "0123456789ABCDEF");
				if (s == NULL)
					return (-1);
				ft_putstr_fd(s, 1);
				n_printed_chars += ft_strlen(s);
				free(s);
			}
			else if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				n_printed_chars++;
			}
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			n_printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (n_printed_chars);
}

int	main(void)
{
	char			c;
	char			*str;
	unsigned int	uint;
	int				*int_ptr;
	int				og_out;
	int				ft_out;

	c = 'c';
	str = "str";
	uint = UINT_MAX;
	og_out = printf("og_printf input string: %s\n", str);
	ft_out = ft_printf("ft_printf input string: %s\n", str);
	printf("og_printf return value when printing \"%s\": %i\n", str, og_out);
	ft_printf("ft_printf return value when printing \"%s\": %i\n", str, ft_out);
	printf("og_printf printing unsigned int: %u\n", uint);
	ft_printf("ft_printf printing unsigned int: %u\n", uint);
	printf("og_printf printing percentage sign: %%\n");
	ft_printf("ft_printf printing percentage sign: %%\n");
	printf("POSITIVE HEX NUMBERS:\n");
	printf("og_printf printing hex: %x\n", 0x1AB);
	ft_printf("ft_printf printing hex: %x\n", 0x1AB);
	printf("og_printf printing hex: %X\n", 0x1AB);
	ft_printf("ft_printf printing hex: %X\n", 0x1AB);
	printf("og_printf printing hex: %x\n", 0x100);
	ft_printf("ft_printf printing hex: %x\n", 0x100);
	printf("og_printf printing hex: %X\n", 0x100);
	ft_printf("ft_printf printing hex: %X\n", 0x100);
	printf("NEGATIVE HEX NUMBERS:\n");
	printf("og_printf printing hex: %x\n", -0x2);
	ft_printf("ft_printf printing hex: %x\n", -0x2);
	printf("og_printf printing hex: %X\n", -0x2);
	ft_printf("ft_printf printing hex: %X\n", -0x2);
	printf("og_printf printing hex: %x\n", -0x2AB);
	ft_printf("ft_printf printing hex: %x\n", -0x2AB);
	printf("og_printf printing hex: %X\n", -0x2AB);
	ft_printf("ft_printf printing hex: %X\n", -0x2AB);
}
