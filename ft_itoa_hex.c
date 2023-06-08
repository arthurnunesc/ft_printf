/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:13:44 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/08 16:52:04 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_allocandretstr_base(int n, int n_len, char *base)
{
	char	*ret_val;
	size_t	base_size;

	base_size = ft_strlen(base);
	ret_val = (char *)ft_calloc((n_len + 1), sizeof(char));
	if (!ret_val)
		return (0);
	while (--n_len >= 0)
	{
		ret_val[n_len] = base[n % base_size];
		n = n / base_size;
	}
	return (ret_val);
}

char	*ft_itoa_hex(int n, int format)
{
	int		n_len;
	int		n_len_aux;
	char	*base;

	if (n == 0)
		return (ft_strdup("0"));
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	n_len = 0;
	n_len_aux = n;
	if (n < 0)
		n_len = 8;
	else
	{
		while (++n_len && (n_len_aux > 15 || n_len_aux < -15))
			n_len_aux = n_len_aux / 16 ;
	}
	return (ft_allocandretstr_base(n, n_len, base));
}
