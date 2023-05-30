/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:59:29 by octoross          #+#    #+#             */
/*   Updated: 2023/05/22 20:02:33 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*slice(char *s, int start, int end)
{
	char	*sliced = malloc(sizeof(char) * (end - start + 1));
	if (!sliced)
		return (NULL);
	sliced[end - start] = '\0';
	int	i = start;
	while (i < end)
	{
		sliced[i - start] = s[i];
		i ++;
	}
	return (sliced);
}
