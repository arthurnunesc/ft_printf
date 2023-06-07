/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:16:46 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/07 19:28:32 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printcharorpercentage(va_list args, int format, int *n_printed_chars);

int	ft_allocprintandfreestr(va_list args, int f, int *n_printed_chars, char *s);

int	ft_parseargs(va_list args, int format, int *n_printed_chars)
{
	if (format == 's' || format == '%')
	{
		if (!ft_printcharorpercentage(args, format, n_printed_chars))
			return (0);
	}
	if (ft_strchr("piduxX", format))
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
			if (!ft_parseargs(args, format[i + 1], &n_printed_chars))
				return (-1);
		}
		else
		{
			if (!ft_putchar_ret(format[i]))
				return (-1);
			n_printed_chars++;
		}
	}
	return (n_printed_chars);
}
