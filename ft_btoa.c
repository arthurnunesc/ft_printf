/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:50:47 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/30 23:57:34 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static char	*ft_createandfillstr(int n, unsigned int n_len, char *base, unsigned int base_size)
{
	char			*result;

	result = (char *)ft_calloc(n_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n_len-- && result[n_len] == 0)
	{
		result[n_len] = base[n % base_size];
		n = n / base_size;
	}
	return (result);
}

int	ft_validatebase(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

char	*ft_btoa(int n, char *base)
{
	unsigned int	n_len;
	int				size_aux;
	int				base_size;

	n_len = 0;
	base_size = ft_strlen(base);
	if (n < 0)
	{
		n_len++;
		size_aux = -n;
	}
	else
	{
		size_aux = n;
	}
	// printf("base_size: %u\n", base_size);
	while (++n_len && (size_aux > base_size - 1))
		size_aux = size_aux / base_size;
	// printf("n_len: %u\n", n_len);
	if (ft_validatebase(base))
		return (ft_createandfillstr(n, n_len, base, base_size));
	return (0);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*base;

	base = "123456789ABCDEF";
	printf("number: 100\n");
	str1 = ft_btoa(100, base);
	printf("ft_basetoa result: %s\n", str1);
	printf("\n");
	printf("number: -100\n");
	str2 = ft_btoa(-100, base);
	printf("ft_basetoa result: %s\n", str2);
}*/
