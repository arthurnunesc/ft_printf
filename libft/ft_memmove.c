/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:56:28 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:50:00 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	size_t			i;

	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	i = 0;
	if (uc_dst == uc_src || len == 0)
		return (dst);
	if (uc_dst < uc_src)
	{
		while (i < len)
		{
			uc_dst[i] = uc_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i--)
			uc_dst[i] = uc_src[i];
	}
	return (dst);
}
