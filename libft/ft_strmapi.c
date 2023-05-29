/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:10:04 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:57:17 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	s_len;
	unsigned int	malloc_size;
	char			*dst;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	malloc_size = s_len + 1;
	dst = ft_calloc(malloc_size, sizeof(char));
	if (dst == NULL)
		return (0);
	while (i < s_len)
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
