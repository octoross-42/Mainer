/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:32:42 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 19:01:05 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 1;
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			size ++;
		}
		return (size);
	}
	return (0);
}
