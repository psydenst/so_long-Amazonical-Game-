/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:26:22 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/26 21:42:56 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*joker;

	if (!*lst)
		return ;
	while (*lst)
	{
		joker = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = joker;
	}
	*lst = NULL;
}
