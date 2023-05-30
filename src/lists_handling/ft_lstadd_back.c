/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:58:26 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 19:00:39 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*next;

	if (*lst)
	{
		next = *lst;
		while (next->next)
			next = next->next;
		next->next = new;
	}
	else
		*lst = new;
}
