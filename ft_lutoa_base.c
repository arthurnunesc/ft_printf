/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:13:44 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/08 16:50:32 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_allocandretstr_base(unsigned long n, int n_len, char *base)
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

char	*ft_lutoa_base(unsigned long n, char *base)
{
	int				n_len;
	unsigned long	n_len_aux;
	size_t			base_size;

	if (n == 0)
		return (ft_strdup("0"));
	n_len = 0;
	n_len_aux = n;
	base_size = ft_strlen(base);
	while (++n_len && (n_len_aux > base_size - 1))
		n_len_aux = n_len_aux / base_size ;
	return (ft_allocandretstr_base(n, n_len, base));
}
