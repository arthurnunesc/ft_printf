/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:34:47 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:56:47 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	malloc_size;

	substr = 0;
	s_len = ft_strlen(s);
	if (len < s_len - start)
		malloc_size = len + 1;
	else
		malloc_size = s_len - start + 1;
	if (start >= s_len)
		return (ft_strdup(""));
	substr = (char *)ft_calloc(malloc_size, sizeof(char));
	if (substr == NULL)
		return (0);
	ft_strlcpy(substr, s + start, malloc_size);
	return (substr);
}
