/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:41:32 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/30 22:26:05 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*ft_createandfillstr(unsigned int n, unsigned int size)
{
	char			*dst;
	unsigned int	i;

	dst = (char *)ft_calloc((size + 1), sizeof(char));
	i = size;
	if (dst == NULL)
		return (0);
	while (i-- > 0 && dst[i] == 0)
	{
		dst[i] = n % 10 + '0';
		n = n / 10;
	}
	return (dst);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	size;
	unsigned int	size_aux;

	size = 0;
	size_aux = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (++size && (size_aux > 9))
		size_aux = size_aux / 10 ;
	return (ft_createandfillstr(n, size));
}
