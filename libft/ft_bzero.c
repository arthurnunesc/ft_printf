/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunes-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:49:11 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/18 00:49:11 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*ucptr_b;

	i = 0;
	ucptr_b = (unsigned char *)b;
	while (i < len)
	{
		ucptr_b[i] = 0;
		i++;
	}
}
