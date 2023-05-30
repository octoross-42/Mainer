/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:29:55 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 18:49:59 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*get_file_buffer(FILE **file)
{
	size_t	fileLen = file_size(file);
	char	*buffer = malloc(sizeof(char) * (fileLen + 1));

	if (!buffer)
		return (NULL);
	
	buffer[fileLen] = '\0';
	int i = 0;
	char	c = 'o';
	while (c != EOF)
	{
		c = fgetc(*file);
		if (c != EOF)
			buffer[i] = c;
		i ++;
	}
	return (buffer);
}
