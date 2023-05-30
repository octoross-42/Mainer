/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_return_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:13:21 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 11:05:55 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*get_return_type(char *function)
{
	int	i = 0;
	while (function[i] != '(')
		i ++;
	if (function[i] != '(')
		return (NULL);
	i -- ;
	while (i >= 0 && isspace(function[i]))
		i --;
	if (i == 0)
		return (NULL);
	printf("function end : %s %d\n", function, i + 1);
	return (slice(function, 0, i + 1));
}
