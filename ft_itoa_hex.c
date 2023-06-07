/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:13:44 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/07 19:16:31 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_createandfillstr(int n, int n_len, char *base)
{
	char	*dst;
	int		base_size;

	base_size = ft_strlen(base);
	dst = (char *)ft_calloc((n_len + 1), sizeof(char));
	if (dst == NULL)
		return (0);
	while (--n_len >= 0 && dst[n_len] == 0)
	{
		dst[n_len] = n % 10 + '0';
		n = n / 10;
	}
	return (dst);
}

char	*ft_itoa_hex(int n, int format)
{
	char	*base;
	int		n_len;
	int		n_len_aux;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	n_len_aux = n;
	n_len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n_len++;
	while (++n_len && (n_len_aux > 9 || n_len_aux < -9))
		n_len_aux = n_len_aux / 10 ;
	return (ft_createandfillstr(n, n_len, base));
}
