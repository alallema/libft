/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:29:39 by alallema          #+#    #+#             */
/*   Updated: 2015/12/02 16:20:33 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*next;

	elem = NULL;
	next = NULL;
	if (!lst || !f)
		return (NULL);
	elem = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (elem == NULL)
		return (NULL);
	next = elem;
	lst = lst->next;
	while (lst)
	{
		next->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (next == NULL)
			return (NULL);
		next = next->next;
		lst = lst->next;
	}
	return (elem);
}
