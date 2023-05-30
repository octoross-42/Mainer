/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:48:37 by octoross          #+#    #+#             */
/*   Updated: 2023/05/28 15:10:55 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*space_around_array_type(char *buffer)
{
	//put exactly space around *s and []s (I think)
	if (!buffer)
		return (NULL);
	int	i = 0;
	int len_buffer = strlen(buffer);
	int	len_new = 0;
	// calcul du len
	while (i < len_buffer)
	{
		if (i + 1 < len_buffer && buffer[i] == ' ' && buffer[i + 1] == '*' || buffer[i] == '*')
		// il y a au maximum un espace a cause du formatage
		{
			len_new += 2;
			if (buffer[i] == ' ')
				i ++;
			i ++;
			while (i < len_buffer && buffer[i] == '*' || (i + 1 < len_buffer && buffer[i] == ' ' && buffer[i + 1] == '*'))
			{
				if (buffer[i] == '*')
					len_new ++;
				i ++;
			}
			if (buffer[i] != ' ')
				len_new ++;
		}
		else
		{
			len_new ++;
			i ++;
		}
	}
	char *with_space_around = malloc(sizeof(char) * (len_new + 1));
	if (!with_space_around)
		return (NULL);
	with_space_around[len_new] = '\0';
	i = 0;
	int j = 0;
	// malloced le truc
	while (i < len_buffer)
	{
		if (i + 1 < len_buffer && buffer[i] == ' ' && buffer[i + 1] == '*' || buffer[i] == '*')
		// il y a au maximum un espace a cause du formatage
		{
			with_space_around[j] = ' ';
			with_space_around[j + 1] = '*';
			j += 2;
			if (buffer[i] == ' ')
				i ++;
			i ++;
			while (i < len_buffer && buffer[i] == '*' || (i + 1 < len_buffer && buffer[i] == ' ' && buffer[i + 1] == '*'))
			{
				if (buffer[i] == '*')
				{
					with_space_around[j] = buffer[i];
					j ++;
				}
				i ++;
			}

			if (buffer[i] != ' ')
			{
				with_space_around[j] = ' ';
				j ++;
			}
		}
		else
		{
			with_space_around[j] = buffer[i];
			i ++;
			j ++;
		}
	}
	return (with_space_around);
}
