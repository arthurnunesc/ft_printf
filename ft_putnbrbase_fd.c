/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:25:20 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/30 22:57:45 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	base_size;

	if (ft_check_base(base) == 0)
	{
		base_size = 0;
		while (base[base_size])
			base_size++;
		if (nbr == -2147483648)
		{
			ft_putstr_fd("-2", fd);
			nbr = 147483684;
		}
		else
		{
			if (nbr < 0)
			{
				ft_putchar_fd('-', fd);
				nbr = -nbr;
			}
			if (nbr > base_size - 1)
				ft_putnbr_base_fd(nbr / base_size, base, fd);
			nbr = nbr % base_size;
			ft_putchar_fd(base[nbr], fd);
		}
	}
}
