/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:59:01 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:59:18 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	**split(char *s, char *sep, int *len)
{
	int	i = 0;
	*len = 0;
	if (!s || strlen(s) == 0)
		return (NULL);
	while (chrstr(s[i], sep))
		i ++;
	
	while (s[i])
	{
		(*len) ++;
		while (s[i] && !chrstr(s[i], sep))
			i ++;
		while (chrstr(s[i], sep))
			i ++;
	}
	char	**split_str = malloc(sizeof(char*) * (*len + 1));
	if (!split_str)
		return (NULL);
	split_str[*len] = 0;
	i = 0;
	*len = 0;
	while (chrstr(s[i], sep))
		i ++;
	while (s[i])
	{
		int	len_in = 0;
		while (s[i + len_in] && !chrstr(s[i + len_in], sep))
			len_in ++;
		split_str[*len] = malloc(sizeof(char) * (len_in + 1));
		if (!split_str)
		{
			free_strs(split_str, *len);
			return (NULL);
		}
		split_str[*len][len_in] = '\0';
		len_in = 0;
		while (s[i] && !chrstr(s[i], sep))
		{
			split_str[*len][len_in] = s[i];
			i ++;
			len_in ++;
		}

		(*len) ++;
		while (chrstr(s[i], sep))
			i ++;
	}
	return (split_str);
}
