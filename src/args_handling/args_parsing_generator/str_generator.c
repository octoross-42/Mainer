/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:12:53 by octoross          #+#    #+#             */
/*   Updated: 2023/05/28 15:03:44 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mainer.h"

char	*str_generator(int argc, char **argv, int nest, int *num) // ici total_nests inutil puisque egal à nest (on est tout au fond)
{

	int	i = 0;
	int	j;
	int	nest_index = 0;
	int	num_index = 0;
	char	*generated = NULL;
	int	len;

	while (i < argc && nest_index < nest)
	{
		j = 0;
		while ((isspace(argv[i][j]) || argv[i][j] == ARGS_IN) && nest_index <= nest)
		{
			if (argv[i][j] == ARGS_IN)
				nest_index ++;
			j ++;
		}
		if (!argv[i][j])
			i ++;
	}
	if (nest_index == nest)
	{
		while (i < argc && num_index < num)
		{
			while (argv[i][j] && (num_index < num))
			{
				if (argv[i][j] == ARGS_IN)
				{
					nest_index ++;
					if (nest_index == nest)
						num_index ++;
				}
				else if (argv[i][j] == ARGS_OUT)
					nest_index --;
				j ++;
			}
			if (!argv[i][j])
			{
				num_index ++;
				j = 0;
				i ++;
			}
		}
		if (num_index == num)
		{
			len = 0;
			while (argv[i][j + len] && argv[i][j + len] != ARGS_OUT)
				len ++;
			generated = malloc(sizeof(char) * (len + 1));
			if (!generated)
				return (NULL);
			generated[len] = 0;
			int start = j;
			while (j - start < len)
			{
				generated[j - start] = argv[i][j];
				j ++;
			}
			if (!strcmp(generated, "NULL"))
			{
				free(generated);
				return (NULL);
			}
			return (generated);
		}
		else 
		// same normalement on ne rentre pas dedans etant donné qu'on a check les args avant
			return (NULL);
	}
	else
		// normalement on ne rentre pas dedans etant donné qu'on a check les args avant
		return (NULL);
}

// int	main(int argc , char **argv)
// {
// 	if (argc > 3)
// 		printf("'%s'\n", str_generator(argc - 3, &argv[3], atoi(argv[1]), atoi(argv[2])));
// 	return (0);
// }