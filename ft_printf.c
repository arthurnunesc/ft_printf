/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:16:46 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/08 17:00:09 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_printcharorpercentage(va_list args, int format, int *n_printed_chars)
{
	if (format == 'c')
	{
		if (!ft_putchar_ret(va_arg(args, int)))
			return (0);
	}
	else if (format == '%')
	{
		if (!ft_putchar_ret('%'))
			return (0);
	}
	*n_printed_chars += 1;
	return (1);
}

int	ft_allocprintandfreestr(va_list args, int f, int *n_printed_chars, char *s)
{
	if (f == 'p')
	{
		s = ft_lutoa_base((unsigned long)va_arg(args, void *),
				"0123456789abcdef");
		if (!ft_putstr_ret("0x"))
			return (ft_freecharptrandreturnzero(s));
		*n_printed_chars += 2;
	}
	else if (f == 'i' || f == 'd')
		s = ft_itoa(va_arg(args, int));
	else if (f == 'u')
		s = ft_utoa_base(va_arg(args, unsigned int), "0123456789");
	else if (f == 'x' || f == 'X')
		s = ft_itoa_hex(va_arg(args, int), f);
	if (!s)
		return (0);
	if (!ft_putstr_ret(s))
		return (ft_freecharptrandreturnzero(s));
	*n_printed_chars += ft_strlen(s);
	free(s);
	return (1);
}

int	ft_parseargs(va_list args, int format, int *n_printed_chars, char *s)
{
	if (format == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		if (!ft_putstr_ret(s))
			return (0);
		*n_printed_chars += ft_strlen(s);
	}
	else if (format == 'c' || format == '%')
	{
		if (!ft_printcharorpercentage(args, format, n_printed_chars))
			return (0);
	}
	else if (ft_strchr("piduxX", format))
	{
		if (!ft_allocprintandfreestr(args, format, n_printed_chars, NULL))
			return (0);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	int				n_printed_chars;

	va_start(args, format);
	i = 0;
	n_printed_chars = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (!ft_parseargs(args, format[i + 1], &n_printed_chars, NULL))
				return (-1);
			i++;
		}
		else
		{
			if (!ft_putchar_ret(format[i]))
				return (-1);
			n_printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (n_printed_chars);
}
