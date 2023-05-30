/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:32:18 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 11:04:26 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*get_args(char *function)
{
	int	i = 0;
	while (function[i] != '(')
		i ++;
	i ++;
	int	start = i;
	int	nest = 1;
	while (function[i])
	{
		if (function[i] == '(')
			nest ++;
		else if (function[i] == ')')
			nest --;
		if (function[i] == ')' && nest == 0)
			break;
		i ++;
	}
	if (!(function[i] == ')' && nest == 0))
		return (NULL);
	return (substr(function, start, i));
}

char	**get_args_types(char *function, int *nbr_arg)
//  get every types in ordre of the arguments of the function which len will be stocked in nbr_arg
{
	char *args = get_args(function);
	printf("args : '%s'\n", args);
	if (!args)
		return (NULL);
	
	char	**split_args = split(args, ",", nbr_arg);
	char	**args_types = (char **)malloc(sizeof(char *) * (*nbr_arg));
	if (!args_types)
		return (NULL);
	int	i = 0;
	while (i < *nbr_arg)
	{
		int len_arg = 0;
		char **splited_arg = split(split_args[i], " ", &len_arg); // ca marche avec les * car formatage
		
		if (!splited_arg)
		{
			free(args);
			free_strs(split_args, *nbr_arg);
			free_strs(args_types, i);
			return (NULL);
		}
		
		args_types[i] = join_until(splited_arg, " ", len_arg - 1);
		
		free_strs(splited_arg, len_arg);
		if (!args_types)
		{
			free(args);
			free_strs(split_args, *nbr_arg);
			free_strs(args_types, i);
			return (NULL);
		}

		i ++;
	}
	
	free(args);
	free_strs(split_args, *nbr_arg);
	return (args_types);
}
