/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:37:18 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:49:47 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*new_dst;
	const char	*new_src;

	new_dst = dst;
	new_src = src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < len)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (dst);
}
