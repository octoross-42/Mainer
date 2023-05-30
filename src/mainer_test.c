/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainer_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:06:57 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 11:04:44 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainer.h"

int	mainer(char pwd[1024], char *fileName, char *functionName, bool man)
{
	if (!c_file(fileName))
	{
		write(0, "Not a .c file\n", 14);
		return (0);
	}
	char	*fileStr = file_path_of(pwd, fileName);
	if (!fileStr)
		return (1);

	FILE* file = NULL;
	file = fopen(fileStr, "r");

	if (!file)
	{
		write(0, "Unable to open ", 15);
		write(0, fileStr, strlen(fileStr));
		write(0, "\n", 1);
		return (1);
	}
	
	// on formate le buffer pour les pointeurs et on enlève les commentaires
	char *formated = formated_buffer(get_file_buffer(&file));
	if (!formated)
	{
		fclose(file);
		free(fileStr);
		return (1);
	}
	
	if (is_function_present(formated, "main"))
	{
		write(1, "Main already exists\n", 20);
		free(formated);
		fclose(file);
		free(fileStr);
		return (0);
	}
	
	char	*function = get_function(formated, functionName);
	if (!function)
	{
		free(formated);
		fclose(file);
		free(fileStr);
		return (1);
	}

	char *return_type = get_return_type(function);
	if (!return_type)
	{
		free(function);
		free(formated);
		fclose(file);
		free(fileStr);
		return (1);
	}

	int	nbr_arg = 0;
	char	**args_types = get_args_types(function, &nbr_arg);
	
	if (!args_types)
	{
		free(return_type);
		free(function);
		free(formated);
		fclose(file);
		free(fileStr);
		return (1);
	}

	printf("function :\n'%s'\nreturn type :\n'%s'\n", function , return_type);
	// int i = 0;
	// while (i < nbr_arg)
	// {
	// 	printf("args_types %d : '%s'", i, args_types[i]);
	// 	i ++;
	// }
	// char **file_prototypes = get_prototypes(formated);
	// if (!file_prototypes)
	// {
	// 	fclose(file);
	// 	free(formated);
	// 	free(fileStr);
	// 	return (1);
	// }
	// if (do_we_know_every_types())
	// on cherche la fonction main dans le fichier, s'il n'y en a pas, on pourra agir
	// bool	noMain = !function_in_prototypes("main", file_prototypes);
	// if (!noMain)
	// {
	// 	write(0, "Main already present in file\n", 29);
	// 	return (0);
	// }
	fclose(file);
	file = fopen(fileStr, "a"); // a pour écrire à la fin
	if (!file)
	{
		write(0, "Unable to write in ", 19);
		write(0, fileStr, strlen(fileStr));
		write(0, "\n", 1);
		return (0);
	}

	fclose(file);
	return (0);
}


int	main(int argc, char **argv)
{
	char	*fileName;
	char	*functionName;
	char	pwd[1024];
	char	*compare_to_man;
	int		error_main = 0;

	if (argc < 2 || argc > 4)
	{
		write(0, "Wtf with the arguments ?\n", 25);
		return (0);
	}

	if (!getcwd(pwd, sizeof(pwd)))
	{
		write(0, "Trouve pas le nom du dossier...\n", 32);
		return (1);
	}

	fileName = argv[1];
	if (argc >= 3)
		functionName = argv[2];
	else
		functionName = functionName_of_path(fileName);
	if (argc == 4)
	{
		compare_to_man = argv[3];
		if (!strcmp(compare_to_man, "man"))
		{
			compare_to_man = str_without_ft(functionName);
			if (!compare_to_man)
			{
				write(0, "Si tu veux comparer au man, ajoute ft_ devant le nom de la fonction man sinon...\n", 81);
				return (1);
			}
		}
	}
	
	error_main = mainer(pwd, fileName, functionName, compare_to_man);
	if (error_main)
	{
		write(0, "Technical problem arised\n", 25);
		return (1);
	}
	return (0);
}
