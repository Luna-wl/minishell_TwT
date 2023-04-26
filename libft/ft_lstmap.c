/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:14:11 by wluedara          #+#    #+#             */
/*   Updated: 2022/09/27 21:15:32 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tem;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		tem = ft_lstnew((*f)(lst->content));
		if (!tem)
		{
			ft_lstclear(&tem, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new, tem);
		lst = lst->next;
	}
	return (new);
}
