/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_comments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:45:43 by octoross          #+#    #+#             */
/*   Updated: 2023/05/28 15:10:46 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*remove_comments(char *buffer)
{
	if (!buffer)
		return (NULL);
	int	i = 0;
	int	len_buffer = strlen(buffer);
	bool *index_to_remove = malloc(sizeof(bool) * len_buffer);
	if (!index_to_remove)
		return (NULL);
	int	to_remove = 0;
	while (i < len_buffer)
	{
		if (buffer[i] == '/' && (i + 1) < len_buffer && buffer[i + 1] == '/')
		{
			index_to_remove[i] = true;
			index_to_remove[i + 1] = true;
			i += 2;
			to_remove += 2;
			while (i < len_buffer && buffer[i] != '\n')
			{
				to_remove ++;
				index_to_remove[i] = true;
				i ++;
			}
		}
		else if (buffer[i] == '/' && (i + 1) < len_buffer && buffer[i + 1] == '*')
		{
			index_to_remove[i] = true;
			index_to_remove[i + 1] = true;
			i += 2;
			to_remove += 2;
			while (i + 1 < len_buffer && !(buffer[i] == '*' && buffer[i + 1] == '/'))
			{
				to_remove ++;
				index_to_remove[i] = true;
				i ++;
			}
			if (buffer[i] == '*' && buffer[i + 1] == '/')
			{
				to_remove += 2;
				index_to_remove[i] = true;
				index_to_remove[i + 1] = true;
				i += 2;
			}
		}
		else
		{
			index_to_remove[i] = false;
			i ++;
		}
	}
	char	*without_line_comments = malloc(sizeof(char) * ((len_buffer - to_remove) + 1));
	if (!without_line_comments)
		return (NULL);
	without_line_comments[len_buffer - to_remove] = '\0';
	i = 0;
	int	j = 0;
	while (i < len_buffer)
	{
		if (!index_to_remove[i])
		{
			without_line_comments[j] = buffer[i];
			j ++;
		}
		i ++;
	}
	free(index_to_remove);
	if (!without_line_comments)
		return (NULL);

	return (without_line_comments);
}
