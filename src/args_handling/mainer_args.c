/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainer_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:20:03 by octoross          #+#    #+#             */
/*   Updated: 2023/05/28 15:05:50 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

t_list	*mainer_args(int argc, char **argv, int nbr_args, char **args_type)
{
	int	nest = 0;
	int	i = 1;
	int	nbr_args_collected = 0;
	int	j;

	while (i < argc)
	{
		if (argv[i][0] == '[')
		{
			nest = 1;
			while (nest > 0 && i < argc)
			{
				
			}
			if (i == argc)
			{
				write(0, "Louche les arguments\n", 21);
				return (NULL);
			}
		}
		i ++;
	}
}