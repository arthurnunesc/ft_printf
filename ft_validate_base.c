/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:34:37 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/08 16:35:06 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}
