/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:40:40 by psydenst          #+#    #+#             */
/*   Updated: 2022/05/27 17:15:45 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*joker;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	joker = ft_lstlast(*lst);
	joker->next = new;
}
