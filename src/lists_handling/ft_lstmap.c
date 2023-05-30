/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:23:33 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 19:01:00 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*starting_node;
	t_list	*previous_node;

	if (lst)
	{
		starting_node = ft_lstnew(f(lst->content));
		if (!starting_node)
			return (0);
		previous_node = starting_node;
		while (lst->next)
		{
			lst = lst->next;
			new_node = ft_lstnew(f(lst->content));
			if (!new_node)
			{
				ft_lstclear(&starting_node, del);
				return (0);
			}
			previous_node->next = new_node;
			previous_node = new_node;
		}
		return (starting_node);
	}
	return (0);
}
