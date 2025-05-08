/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:35:11 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 18:35:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cur;

	if (!lst || !del)
		return ;
	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		ft_lstdelone(cur, del);
		cur = tmp;
	}
	*lst = NULL;
}
