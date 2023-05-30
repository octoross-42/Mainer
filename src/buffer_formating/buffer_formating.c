/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_formating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:09:04 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:59:18 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*formated_buffer(char *buffer)
{
	int	useless = 0;
	char	*commented = NULL;
	char	*spaces = NULL;
	char	*newlines = NULL;
	char	*formated = NULL;
	char	**splited = NULL;

	commented = remove_comments(buffer);
	free(buffer);
	if (!commented)
		return (NULL);
	splited = split(commented, "\n", &useless);
	free(commented);
	if (!splited)
		return (NULL);
	spaces = join(splited, "\n");
	free_strs(splited, useless);
	if (!spaces)
		return (NULL);
	splited = split(spaces, " ", &useless);
	free(spaces);
	if (!splited)
		return (NULL);
	newlines = join(splited, " ");
	free_strs(splited, useless);
	if (!newlines)
		return (NULL);
	formated = space_around_array_type(newlines);
	free(newlines);
	if (!formated)
		return (NULL);
	return (formated);
}
