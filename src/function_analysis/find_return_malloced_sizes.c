/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_return_malloced_sizes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 05:43:14 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:59:18 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*size_of(char *attribution)
{
	// alloc : malloc, calloc, realloc, reallocarray
	char	*size_alloc = NULL;
	int	l = 0;
	while (attribution[l])
	{
		int	j = 0;
		while (attribution[l + j] == "malloc"[j])
			j ++;
		l += j;
		if (j == 6)
		{
			if (attribution[l] == '(')
			{
				int nest = 0;
				j = 0;
				while (attribution[l + j])
				{
					if (attribution[l + j] == '(')
						nest ++;
					else if (attribution[l + j] == ')')
						nest --;
					if (attribution[l + j] == ')' && nest == 0)
					{
						size_alloc = slice(attribution, l + 1, l + j);
						if (!size_alloc)
							return (NULL);
						// sizeof(...) * ou * sizeof(...)
					}
					j ++;
				}
				// size c'est tout simplement ce qu'il y a entre les parenthèses divise par sizeof
			}
		}
		else
		{
			j = 0;
			while (attribution[l + j] == "calloc"[j])
				j ++;
			l += j;
			if (j == 6)
			{
				if (attribution[l] == '(')
				{
					int nest = 1;
					j = 0;
					while (attribution[l + j] && attribution[l + j] != ',')
						j ++;
					if (attribution[l + j] == ',')
					{
						size_alloc = slice(attribution, l + 1, l + j);
						if (!size_alloc)
							return (NULL);
					}
				}
			}
			else
			{
				j = 0;
				while (attribution[l + j] == "realloc"[j])
					j ++;
				l += j;
				if (j == 7)
				{
					if (attribution[l] == '(')
					{
						int nest = 1;
						while (attribution[l] && attribution[l] != ',')
						{
							if (attribution[l] == '(')
								nest ++;
							else if (attribution[l] == ')')
								nest --;			
							l ++;
						}
						if (attribution[l] == ',')
						{
							int nest = 1;
							j = 0;
							while (attribution[l + j])
							{
								if (attribution[l + j] == '(')
									nest ++;
								else if (attribution[l + j] == ')')
									nest --;
								if (attribution[l + j] == ')' && nest == 0)
								{
									
								}
								j ++;
							}
						}
						// size c'est tout simplement ce qu'il y a entre les parenthèses
					}
				}
				else
				{
					j = 0;
					while (attribution[l + j] == "reallocarray"[j])
						j ++;
					l += j;
					if (j == 12)
					{
						if (attribution[l] == '(')
						{
							int nest = 1;
							j = 0;
							while (attribution[l + j])
							{
								if (attribution[l + j] == '(')
									nest ++;
								else if (attribution[l + j] == ')')
									nest --;
								if (attribution[l + j] == ')' && nest == 0)
								{
									
								}
								j ++;
							}
							// size c'est tout simplement ce qu'il y a entre les parenthèses
						}
					}
					else
					{

					}
				}	
			}
		}
		l ++;
	}
	return (size_alloc);
}

char	*attribution_of(char *var_name, char *functionStr, char **args_function)
{
	char *attribution = NULL;
	int	nombre_attributions = 0;
	int	i = 0;
	while (functionStr[i])
	{
		int	j = 0;
		while (var_name[j] && functionStr[i + j] == var_name[j])
			j ++;
		i += j;
		if (!var_name[j]) // j == strlen(return_insides[return_i])
		{
			int k = i;
			while (functionStr[k] && functionStr[k] != '{' && functionStr[k] != ';')
				k ++;
			if (functionStr[k] == ';')
			{
				while (functionStr[i] == ' ')
					i ++;
				if (functionStr[i] == '=' && functionStr[i + 1] != '=') // normalement le second est inutile mais bon on sait jamais
				{
					nombre_attributions ++;
					if (nombre_attributions == 1)
					{
						while (functionStr[i] == ' ')
							i ++;
						if (attribution)
							free(attribution);
						attribution = slice(functionStr, i + 1, k);
						if (!attribution)
							return (NULL);
					}
					else
						return (NULL);
				}
			}
			i = k;
		}
		else
			i += j;
		i ++;
	}
	if (nombre_attributions == 1)
		return (attribution);
	if (attribution)
		free(attribution);
	return (NULL);
}



char	**get_return_insides(char *buffer, char *functionStr)
{
	int nbr_return_not_null = 0;
	int	i = 0;
	while (buffer[i + 7]) // return ;
	{
		if (buffer[i] == 'r' && buffer[i + 1] == 'e' && buffer[i + 2] == 't' && buffer[i + 3] == 'u' && buffer[i + 4] == 'r' && buffer[i + 5] == 'n')
		{
			char *potential_return = NULL;
			int j = i + 5;
			while (buffer[j] != ';')
				j ++;
			potential_return = slice(buffer, i + 6, j);
			if (!potential_return)
			{
				free(functionStr);
				return (NULL);
			}
			int len_split = 0;
			char **splited = split(potential_return, " \n\t\v\f\r", &len_split);
			if (!splited)
			{
				free(functionStr);
				free(potential_return);
				return (NULL);
			}
			char *joined = join(splited, " ");
			if (!joined)
			{
				free_strs(splited, len_split);
				free(functionStr);
				free(potential_return);
				return (NULL);
			}
			int nbr_around_parenthesis = 0;
			while (joined[nbr_around_parenthesis] == '(' && joined[strlen(joined) - 1 - nbr_around_parenthesis] == ')')
				nbr_around_parenthesis ++;
			int len_return = strlen(joined) - 2 * nbr_around_parenthesis;
			char *simple_return = malloc(sizeof(char) * (len_return + 1));
			if (!simple_return)
			{
				free(joined);
				free_strs(splited, len_split);
				free(functionStr);
				free(potential_return);
				return (NULL);
			}
			simple_return[len_return] = '\0';
			int k = nbr_around_parenthesis;
			while (k < len_return + nbr_around_parenthesis)
			{
				simple_return[k - nbr_around_parenthesis] = joined[k];
				k ++;
			}
			if (strcmp(simple_return, "NULL"))
				nbr_return_not_null ++;

			free(joined);
			free_strs(splited, len_split);
			free(potential_return);
			free(simple_return);
		}
		i ++;
	}

	char **returns = malloc(sizeof(char *) * (nbr_return_not_null + 1));
	if (!returns)
	{
		free(functionStr);
		return (NULL);
	}
	returns[nbr_return_not_null] = 0;

	i = 0;
	nbr_return_not_null = 0;
	while (buffer[i + 7]) // return ;
	{
		if (buffer[i] == 'r' && buffer[i + 1] == 'e' && buffer[i + 2] == 't' && buffer[i + 3] == 'u' && buffer[i + 4] == 'r' && buffer[i + 5] == 'n')
		{
			int j = i + 6;
			while (buffer[j] != ';')
				j ++;
			char *potential_return = slice(buffer, i + 6, j);
			if (!potential_return)
			{
				free(functionStr);
				return (NULL);
			}
			int len_split = 0;
			char **splited = split(potential_return, " \n\t\v\f\r", &len_split);
			if (!splited)
			{
				free(functionStr);
				free(potential_return);
				return (NULL);
			}
			char *joined = join(splited, " ");
			if (!joined)
			{
				free_strs(splited, len_split);
				free(functionStr);
				free(potential_return);
				return (NULL);
			}
			int nbr_around_parenthesis = 0;
			while (joined[nbr_around_parenthesis] == '(' && joined[strlen(joined) - 1 - nbr_around_parenthesis] == ')')
				nbr_around_parenthesis ++;
			int len_return = strlen(joined) - 2 * nbr_around_parenthesis;
			char *simple_return = malloc(sizeof(char) * (len_return + 1));
			if (!simple_return)
			{
				free(joined);
				free_strs(splited, len_split);
				free(functionStr);
				free(potential_return);
				return (NULL);
			}
			simple_return[len_return] = '\0';
			int k = nbr_around_parenthesis;
			while (k < len_return + nbr_around_parenthesis)
			{
				simple_return[k - nbr_around_parenthesis] = joined[k];
				k ++;
			}
			if (strcmp(simple_return, "NULL"))
			{
				returns[nbr_return_not_null] = simple_return;
				nbr_return_not_null ++;
			}
			else
				free(simple_return);
				
			free(joined);
			free_strs(splited, len_split);
			free(potential_return);
		}
		i ++;
	}
	return (returns);
	// free(functionStr);
	// return (NULL);
}


char	*divide_by_sizeof(char *size)
{
	int	i = 0;
	while (size[i])
	{
		int	j = 0;
		int tampon = i;
		while (size[i + j] == "sizeof("[j])
			j ++;
		i += j;
		if (j == 7)
		{
			// pour l'instant on ne vérifie pas ce qu'il y a à l'intérieur -> TODO
			int	nest = 1;
			while (size[i])
			{
				if (size[i] == '(')
					nest ++;
				else if (size[i] == ')')
					nest --;
				if (size[i] == ')' && nest == 0)
				{
					i ++;
					// on va chercher le fois avant ou apres -> * sizeof(...) ou sizeof(...) *
					while (size[i] == ' ')
						i ++;
					if (size[i] == '*')
					{
						i ++;
						while (size[i] == ' ')
							i ++;
						char *divided = malloc(sizeof(char) * (strlen(size) - (i - tampon) + 1));
						if (!divided)
							return (NULL);
						divided[strlen(size) - (i - tampon)] = '\0';
						// blabla sizeof(...) * ' ' (*n)
						//        tampon            i
						int	k = 0;
						while (k < tampon)
						{
							divided[k] = size[k];
							k ++;
						}
						while (size[k + i - tampon])
						{
							divided[k] = size[k + i - tampon];
							k ++;
						}
						return (divided);
					}
					else
					{
						// alors le fois est avant
						// on se place avant tampon
						tampon --;
						if(tampon >= 0)
						{
							while (size[tampon] == ' ')
								tampon --;
							if (size[tampon] == '*')
							{
								tampon --;
								while (size[tampon] == ' ')
									tampon --;
								printf("caca : %c %ld %d\n", size[tampon], strlen(size), i);
								char *divided = malloc(sizeof(char) * (strlen(size) - (i - (tampon + 1)) + 1));
								if (!divided)
									return (NULL);
								divided[strlen(size) - (i - (tampon + 1))] = '\0';
								// blabla * sizeof(...)
								//        tampon      i
								int	k = 0;
								while (k <= tampon)
								{
									divided[k] = size[k];
									k ++;
								}
								while (size[k + i - tampon])
								{
									divided[k] = size[k + i - tampon];
									k ++;
								}
								return (divided);
							}
							else
							{
								// sizeof tout seul remplacé par 1 ou bien des additions et la j'ai la flemme
								return (NULL);
							}
						}
					}
				}
				i ++;
			}
		}
		i ++;
	}
}

char	*find_return_sizes(char *return_type, char *functionName, char *buffer)
{
	// le buffer a ete formate
	// la taille est celle donnée aux allocs
	// alloc : malloc, calloc, realloc, reallocarray

	// on fait simple : il faut que les trucs dans les allocs soient directement definis (en parametres ou avec un unique =)

	/*
	s'il n'y a qu'un return ou bien un return et d'autres NULL, on checke que ce soit un simple nom (sinon trop chiant) -> pas de fonction ou d'operations
	 
	*/

	int	size_data = sizeof_datatype(return_type);
	if (size_data < 0)
		return (NULL);

	char *functionStr = get_function(buffer, functionName);
	if (!functionStr)
		return (NULL);
	char **return_insides = get_return_insides(buffer, functionStr);
	if (!return_insides)
	{
		free(functionStr);
		return (NULL);
	}
	
	// on compte les returns non NULL

	int len_return_insides = 0;
	int	len_returns = 0;
	while (return_insides[len_return_insides])
	{
		if (strcmp(return_insides[len_return_insides], "NULL"))
			len_returns ++;
		len_return_insides ++;
	}

	if (len_returns == 1)
	{
		int return_i = 0;
		while (!strcmp(return_insides[return_i], "NULL"))
			return_i ++;
		int len_split = 0;
		char **return_split = split(return_insides[return_i], " ()[]", &len_split);
		if (!return_split)
		{
			free_strs(return_insides, len_return_insides);
			free(functionStr);
			return (NULL);
		}
		if (len_split == 1) // ca marche parce qu'un appelle de fonction il y a le nom de la fonction puis ( puis autre chose et [indice]
		{
		/*le return truc n'appelle pas de fonction et est tel quel qu'il est nommé
		on va chercher le truc bidule dans la fonction pour savoir quand elle est créée, c'est forcément un tableau donc alloc sinon je me fous en l'air 
			s'il y a plusieurs allocs, on se casse
			on regarde ce qu'il ya comme ça : plusieurs cas en fonction de la méthode d'allocs
				c'est forcément un int donc on sépare par les opérations (+ - * / %) et les fonctions appelées donc () et [] pour les tableaux (on peut reproduire)
					là normalement on a split (on n'oublie pas les espaces dans le split) et il nous reste que les noms de variables, 
					on les cherche dans les arguments ou sinon c'est trop compliqué 
						(si t'as le temps : si c'est directement attribué (on compte le nombre d'attribution avec = ou ++))*/

			
			// TODO args_function
			char **args_function = NULL;
			char *attribution = attribution_of(return_insides[return_i], functionStr, args_function);
			if (!attribution)
			{
				free_strs(return_insides, len_return_insides);
				free(functionStr);
				return (NULL);
			}
			char *size_alloc = size_of(attribution);
			free(attribution);
			if (!size_alloc)
			{
				free_strs(return_insides, len_return_insides);
				free(functionStr);
				return (NULL);
			}
			
			// tempo :
			write(1, "size_alloc : ", strlen("size_alloc : "));
			write(1, size_alloc, strlen(size_alloc));
			write(1, "\n", 1);
			free(functionStr);
			free_strs(return_insides, len_return_insides);
			free_strs(return_split, len_split);
			char *size_nbr = divide_by_sizeof(size_alloc);
			write(1, "size_nbr : ", strlen("size_nbr : "));
			write(1, size_nbr, strlen(size_nbr));
			write(1, "\n", 1);
			if (size_nbr)
			{
				free(size_alloc);
				return (size_nbr);
			}
			return (size_alloc); // TODO : diviser par sizeof manuellement
		}
		free_strs(return_split, len_split);
	}

	free_strs(return_insides, len_return_insides);
	free(functionStr);
	
	return (NULL);
}

// int main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		FILE *f = fopen(argv[1], "r");
// 		char buffer[1024];
// 		int i = 0;
// 		char	c = 'o';
// 		while (c != EOF)
// 		{
// 			c = fgetc(f);
// 			if (c != EOF)
// 				buffer[i] = c;
// 			i ++;
// 		}
// 		buffer[i] = '\0';
// 		fclose(f);
// 		printf("%s\n", buffer);
// 		char **truc = get_return_names(buffer, "ft_atoi");
// 		printf("truc machun : \n");
// 	}
// 	return (0);
// }