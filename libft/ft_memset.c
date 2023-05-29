/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:41:25 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:51:17 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*ucptr_dest;
	unsigned char	uc_c;

	ucptr_dest = (unsigned char *)dest;
	uc_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ucptr_dest[i] = uc_c;
		i++;
	}
	return ((void *)ucptr_dest);
}
