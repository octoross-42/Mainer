/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_without_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:23:46 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 19:01:56 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*str_without_ft(char *str)
{
	int		i;
	char	*s;
	
	if (!str || strlen(str) < 3 || str[0] != 'f' || str[1] != 't' || str[2] != '_')
		return (NULL);
	s = (char *)malloc(sizeof(char) * (strlen(str) - 2));
	if (!s)
		return (NULL);
	s[strlen(str) - 3] = '\0';
	i = 0;
	while (i < strlen(str) - 3)
	{
		s[i] = str[i + 3];
		i ++;
	}
	return (s);
}
