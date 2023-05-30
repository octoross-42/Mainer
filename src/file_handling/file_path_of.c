/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:16:39 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 18:35:54 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*file_path_of(char pwd[1024], char *fileName)
{
	size_t	len = strlen(pwd) + strlen(fileName) + 1;
	char	*path = malloc(sizeof(char) * (len + 1));
	if (!path)	
		return (NULL);
	path[len] = '\0';
	size_t	i = 0;
	while (i < strlen(pwd))
	{
		path[i] = pwd[i];
		i ++;
	}
	path[i] = '/';
	i ++;
	while (i < len)
	{
		path[i] = fileName[i - strlen(pwd) - 1];
		i ++;
	}
	return (path);
}
