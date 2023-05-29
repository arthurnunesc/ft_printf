/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:36:55 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:49:28 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*ucptr_b1;
	unsigned char	*ucptr_b2;

	i = 0;
	ucptr_b1 = (unsigned char *)b1;
	ucptr_b2 = (unsigned char *)b2;
	while (i < len)
	{
		if (ucptr_b1[i] != ucptr_b2[i])
			return (ucptr_b1[i] - ucptr_b2[i]);
		i++;
	}
	return (0);
}
