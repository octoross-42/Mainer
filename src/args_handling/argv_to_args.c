/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:00:15 by octoross          #+#    #+#             */
/*   Updated: 2023/05/28 15:06:27 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*argv_to_args(int argc, char **argv)
{
	if (!argv || argc < 0)
		return (NULL);
	char	**formated = (char **)malloc(sizeof(char *) * argc);
	if (!formated)
		return (NULL);
	formated[argc] = 0;
	int	i = 1;
	while (i < argc)
	{
		formated[i - 1] = argv[i];
		i ++;
	}
	return (join(formated, " "));
}
