/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:35:30 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:52:39 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc_c;
	unsigned int	i;

	i = 0;
	uc_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == uc_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == uc_c)
		return ((char *)&s[i]);
	return (NULL);
}
