/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:35:30 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:58:53 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	uc_c;
	char			*dst;

	i = 0;
	dst = 0;
	uc_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == uc_c)
			dst = (char *)&s[i];
		s++;
	}
	if (s[i] == uc_c)
		dst = (char *)&s[i];
	return (dst);
}
