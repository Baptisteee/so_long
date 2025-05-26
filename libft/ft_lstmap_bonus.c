/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 08:03:24 by babodere          #+#    #+#             */
/*   Updated: 2025/04/25 20:07:56 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*retval;
	t_list	*temp;

	retval = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew(lst->content);
		if (!temp)
		{
			ft_lstclear(&retval, del);
			return (NULL);
		}
		temp->content = f(temp->content);
		ft_lstadd_back(&retval, temp);
		lst = lst->next;
	}
	return (retval);
}
