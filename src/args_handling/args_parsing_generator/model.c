#include "../mainer.h"


char	***strss_generator(int argc, char **argv, int nest, int *num, int total_nests)
{
	int	num_index* = malloc(sizeof(int) * (total_nests));
	int	nest_index = 0;
	while (nest_index < total_nests)
		num_index[nest_index++] = 0;
	char	*generated = NULL;
	int	i;
	int	j;
	int	len;

	nest_index = 0;
	i = 0;
	while (i < argc && intscmp(num, num_index))
	// on veut arriver à l'élement aux coordonnées spécifiées dans num
	{
		j = 0;
		while (argv[i][j] && intscmp(num, num_index))
		{
			if (argv[i][j] == ARGS_IN)
			{
				nest_index ++;
				num_index[nest_index - 1] ++;
			}
			else if (argv[i][j] == ARGS_OUT)
			{
				nest_index --;
				num_index[nest_index - 1] --;
			}
			j ++;
		}
		if (!argv[i][j])
		{
			num_index[nest_index - 1] ++;
			j = 0;
			i ++;
		}
	}
	if (!intscmp(num, num_index))
	{
		printf("resultat des courses : %d\n", len);
		generated = malloc(sizeof(char **) * (len + 1));
		if (!generated)
			return (NULL);
		generated[len] = 0;
		// after : 
		/*
		i = 0;
		int num = 0;
		while (i < len)
		{
			num[nest] = i;
			generated[i] = strss_generator(argc, argv, nest + 1, num);
			if (!generated[i])
				free_strsss(generated, i);
			i ++;
		}
		*/
	}
	else 
	// normalement on ne rentre pas dedans etant donné qu'on a check les args avant
		return (NULL);
}

int	main(int argc , char **argv)
{
	if (argc > 3)
		strss_generator(argc - 3, &argv[3], atoi(argv[1]), atoi(argv[2]));
	return (0);
}