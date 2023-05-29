/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:02:00 by anunes-c          #+#    #+#             */
/*   Updated: 2023/05/29 19:41:17 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_lstrealclear(t_list *lst, void (*del)(void *))
{
	t_list	*next_node;

	while (lst)
	{
		next_node = (lst)->next;
		ft_lstdelone(lst, del);
		lst = next_node;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	ft_lstrealclear(*lst, del);
	*lst = NULL;
}
