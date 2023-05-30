/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:14:24 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:19:10 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*substr(char *str, int start, int end)
// end exclus
{
	if (!str)
		return (NULL);

	start = max(start, 0);
	end = min(strlen(str), end);
	char	*sub = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!sub)
		return (NULL);
	sub[end - start] = '\0';
	
	int i = 0;
	while (i < end - start)
	{
		sub[i] = str[start + i];
		i ++;
	}
}
