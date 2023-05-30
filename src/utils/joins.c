/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:02 by octoross          #+#    #+#             */
/*   Updated: 2023/05/22 20:02:41 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*join(char **split_str, char *space)
{
	int	len_join = 0;
	int	len_split = 0;
	while (split_str[len_split])
	{
		len_join += strlen(split_str[len_split]);
		len_split ++;
	}
	if (!split_str || len_split == 0)
		return (NULL);
	char *joined = malloc(sizeof(char) * ((len_split - 1) * strlen(space) + len_join + 1));
	if (!joined)
		return (NULL);
	joined[(len_split - 1) * strlen(space) + len_join] = '\0';
	len_split = 0;
	len_join = 0;
	while (split_str[len_split])
	{
		int i = 0;
		while (split_str[len_split][i])
		{
			joined[len_join] = split_str[len_split][i],
			i ++;
			len_join ++;
		}
		if (split_str[len_split + 1])
		{
			i = 0;
			while (space[i])
			{
				joined[len_join] = space[i],
				i ++;
				len_join ++;
			}
		}
		len_split ++;
	}
	return (joined);
}


char	*join_until(char **split_str, char *space, int until)
{
	int	len_join = 0;
	int	len_split = 0;
	while (len_split < until)
	{
		len_join += strlen(split_str[len_split]);
		len_split ++;
	}
	if (!split_str || len_split == 0)
		return (NULL);
	char *joined = malloc(sizeof(char) * ((until - 1) * strlen(space) + len_join + 1));
	if (!joined)
		return (NULL);
	joined[(len_split - 1) * strlen(space) + len_join] = '\0';
	len_split = 0;
	len_join = 0;
	while (len_split < until)
	{
		int i = 0;
		while (split_str[len_split][i])
		{
			joined[len_join] = split_str[len_split][i],
			i ++;
			len_join ++;
		}
		if (len_split + 1 < until)
		{
			i = 0;
			while (space[i])
			{
				joined[len_join] = space[i],
				i ++;
				len_join ++;
			}
		}
		len_split ++;
	}
	return (joined);
}
