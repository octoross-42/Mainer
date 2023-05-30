/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:00:21 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:59:21 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

void	free_strs(char **split_str, int len)
{
	int	i = 0;
	while (i < len)
	{
		free(split_str[i]);
		i ++;
	}
	free(split_str);
}

void	attribute_chars(char *s, char *str, int starting)
{
	int	i = starting;
	while (str[i - starting])
	{
		s[i] = str[i - starting];
		i ++;
	}
}
