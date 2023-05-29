/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:15:56 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:48:35 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*ucptr_b;

	i = 0;
	uc = (unsigned char)c;
	ucptr_b = (unsigned char *)b;
	while (i < len)
	{
		if (ucptr_b[i] == uc)
			return ((void *)&ucptr_b[i]);
		i++;
	}
	return (NULL);
}
