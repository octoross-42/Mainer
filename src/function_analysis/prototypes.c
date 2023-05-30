/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:07:18 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:59:18 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*get_prototype_name(char *prototype)
// get the name of the prototype's function
{
	int i = strlen(prototype) - 2;
	while (i >= 0)
	{
		if (prototype[i + 1] == '(')
		{
			int j = i;
			while (j >= 0 && !chrstr(prototype[j], " \t\n\f\r\v*"))
				j --;
			if (chrstr(prototype[j], " \t\n\f\r\v*"))
				return (slice(prototype, j + 1, i + 1));
		}
		i --;
	}
	return (NULL);
}

int	get_name_index(char *prototype)
// get the index of the start of the name of the prototype's function
{
	int i = strlen(prototype) - 2;
	while (i >= 0)
	{
		if (prototype[i + 1] == '(')
		{
			int j = i;
			while (j >= 0 && !chrstr(prototype[j], " \t\n\f\r\v*"))
				j --;
			if (chrstr(prototype[j], " \t\n\f\r\v*"))
				return (j + 1);
		}
		i --;
	}
	return (-1);
}

bool	function_in_prototypes(char *functionName, char **prototypes)
// check if there's a prototype with a function named functionName is in prototypes
{
	int i = 0;
	while (prototypes[i])
	{
		int j = 0;
		char	*namePrototype = get_prototype_name(prototypes[i]);
		while (functionName[j] && namePrototype[j] == functionName[j])
			j ++;
		
		free(namePrototype);
		if (functionName[j] == '\0')
			return (true);
		i ++;
	}
	return (false);
}

char	*get_prototype_which_name_is(char **prototypes, char *name)
// actually gets the prototype which is named name in prototypes
{
	int i = 0;
	while (prototypes[i])
	{
		int j = 0;
		char	*namePrototype = get_prototype_name(prototypes[i]);
		while (name[j] && namePrototype[j] == name[j])
			j ++;
		free(namePrototype);
		if (name[j] == '\0')
			return (prototypes[i]);
		i ++;
	}
	return (NULL);
}


char	**get_prototypes(char *buffer)
// get every prototypes of functions who are declared in buffer
{
	char	**prototypes = NULL;
	
	int i = strlen(buffer) - 1;
	int	nbr_proto = 0;
	int nest = 0;
	while (i >= 0)
	{
		int	j = i -1;
		if (buffer[i] == '{' && nest == 1)
		{
			while (j > 0 && buffer[j] != '#' && buffer[j] != '}' && buffer[j] != ';' && buffer[j] != '>' && (buffer[j] != '/' && (buffer[j - 1] != '/' || buffer[j - 1] != '*')))
				j --;

			if (j > 0 && buffer[j - 1] == '/' && buffer[j] == '/' || buffer[j] == '#')
			{
				while (buffer[j] != '\n' && buffer[j])
					j ++;
			}
			if (j == 0 || buffer[j] == '}' || buffer[j] == ';' || buffer[j] == '>' || (j > 0 && (buffer[j] == '/' && buffer[j - 1] == '*') || buffer[j] == '\n'))
			{
				if (j != 0)
					j ++;

				char **split_proto = NULL;
				int	len_proto = 0;
				char *sliced = slice(buffer, j, i);
				if (!sliced)
					return (NULL);
				split_proto = split(sliced, " \n\t\r\f\v", &len_proto);
				free(sliced);
				if (!split_proto)
					return (NULL);
				if (len_proto > 0)
					nbr_proto ++;
				free_strs(split_proto, len_proto);
				j --;
			}
			nest = 0;
		}
		else if (buffer[i] == '}')
		{
			nest ++;
		}
		else if (buffer[i] == '{')
			nest --;
		i = j;
	}
	prototypes = malloc(sizeof(char *) * (nbr_proto + 1));
	if (!prototypes)
		return (NULL);
	prototypes[nbr_proto] = 0;
	nbr_proto = 0;
	i = strlen(buffer) - 1;
	while (i >= 0)
	{
		int j = i -1;
		if (buffer[i] == '{' && nest == 1)
		{
			while (j > 0 && buffer[j] != '#' && buffer[j] != '}' && buffer[j] != ';' && buffer[j] != '>' && (buffer[j] != '/' && (j > 0 && (buffer[j - 1] != '/' || buffer[j - 1] != '*'))))
				j --;

			if (j > 0 && buffer[j - 1] == '/' && buffer[j] == '/' || buffer[j] == '#')
			{
				while (buffer[j] != '\n' && buffer[j])
					j ++;
			}
			if (j == 0 || buffer[j] == '}' || buffer[j] == ';' || buffer[j] == '>' || (j > 0 && buffer[j] == '/' && buffer[j - 1] == '*') || buffer[j] == '\n')
			{
				if (j != 0)
					j ++;

				char **split_proto = NULL;
				int	len_proto = 0;
				char *sliced = slice(buffer, j, i);
				split_proto = split(sliced, " \n\t\r\f\v", &len_proto);
				
				if (!split_proto)
					return (NULL);
				
				if (len_proto > 0)
				{
					prototypes[nbr_proto] = join(split_proto, " ");
					if (!prototypes[nbr_proto])
					{
						free_strs(prototypes, nbr_proto);
						return (NULL);
					}
					nbr_proto ++;
				}
				free(sliced);
				free_strs(split_proto, len_proto);
				j --;
			}
			nest = 0;
		}
		else if (buffer[i] == '}')
		{
			nest ++;
		}
		else if (buffer[i] == '{')
			nest --;
		i = j;
	}
	return (prototypes);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		char **protos = get_prototypes(argv[1]);
// 		if (!protos)
// 			return (1);
// 		int nbr_proto = 0;
// 		while (protos[nbr_proto])
// 			nbr_proto ++;
// 		char *p = get_prototype_which_name_is(protos, "main");
// 		free_strs(protos, nbr_proto);
// 		if (!p)
// 			return (1);
// 		free(p);	
// 	}
// 	return (0);
// }
