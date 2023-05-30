// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mainer.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/28 02:05:09 by octoross          #+#    #+#             */
// /*   Updated: 2023/05/28 15:14:41 by octoross         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "mainer.h"

// char	*file_path_of(char pwd[1024], char *fileName)
// {
// 	int	len = strlen(fileName) + strlen(pwd);
// 	char *file = malloc(sizeof(char) * (len + 2));
// 	if (!file)
// 		return (NULL);
// 	file[len + 1] = '\0';

// 	int	i = 0;
// 	while (pwd[i])
// 	{
// 		file[i] = pwd[i];
// 		i ++;
// 	}
// 	file[i++] = '/';
// 	int j = 0;
// 	while (fileName[j])
// 	{
// 		file[i + j] = fileName[j];
// 		j ++;
// 	}
// 	return (file);
// }



// int	mainer(char pwd[1024], char *fileName, bool man)
// {
// 	char	*fileStr = file_path_of(pwd, fileName);
// 	if (fileStr)
// 	{
// 		FILE* file = NULL;
// 		file = fopen(fileStr, "r");
// 		if (!file)
// 		{
// 			write(0, "Unable to open ", 15);
// 			write(0, fileStr, strlen(fileStr));
// 			write(0, "\n", 1);
// 		}
// 		else
// 		{
// 			// on malloc puis remplit le buffer du texte du fichier
// 			fseek(file, 0, SEEK_END);
// 			long int fileLen = ftell(file);
// 			rewind(file);

// 			char  *buffer = NULL;
// 			buffer = malloc(sizeof(char) * (fileLen + 1));
// 			if (!buffer)
// 				return (1);
// 			buffer[fileLen] = '\0';
// 			int i = 0;
// 			char	c = 'o';
// 			while (c != EOF)
// 			{
// 				c = fgetc(file);
// 				if (c != EOF)
// 					buffer[i] = c;
// 				i ++;
// 			}
			
// 	int	len = strlen(fileName) + strlen(pwd);
// 	char *file = malloc(sizeof(char) * (len + 2));
// 	if (!file)
// 		return (NULL);
// 	file[len + 1] = '\0';

// 	int	i = 0;
// 	while (pwd[i])
// 	{
// 		file[i] = pwd[i];
// 		i ++;
// 	}
// 	file[i++] = '/';
// 	int j = 0;
// 	while (fileName[j])
// 	{
// 		file[i + j] = fileName[j];
// 		j ++;
// 	}
// 	return (file);
// }



// int	mainer(char pwd[1024], char *fileName, bool man)
// {
// 	char	*fileStr = file_path_of(pwd, fileName);
// 	if (fileStr)
// 	{
// 		FILE* file = NULL;
// 		file = fopen(fileStr, "r");
// 		if (!file)
// 		{
// 			write(0, "Unable to open ", 15);
// 			write(0, fileStr, strlen(fileStr));
// 			write(0, "\n", 1);
// 		}
// 		else
// 		{
// 			// on malloc puis remplit le buffer du texte du fichier
// 			fseek(file, 0, SEEK_END);
// 			long int fileLen = ftell(file);
// 			rewind(file);

// 			char  *buffer = NULL;
// 			buffer = malloc(sizeof(char) * (fileLen + 1));
// 			if (!buffer)
// 				return (1);
// 			buffer[fileLen] = '\0';
// 			int i = 0;
// 			char	c = 'o';
// 			while (c != EOF)
// 			{
// 				c = fgetc(file);
// 				if (c != EOF)
// 					buffer[i] = c;
// 				i ++;
// 			}
			
// 			// on formate le buffer pour les pointeurs et on enlève les commentaires
// 			char *formated = NULL;
// 			formated = formated_buffer(buffer);
// 			free(buffer);
// 			if (!formated)
// 			{
// 				fclose(file);
// 				free(fileStr);
// 				return (1);
// 			}


// 			bool	noMain = false;
// 			char **file_prototypes = get_prototypes(formated);
// 			if (!file_prototypes)
// 			{
// 				fclose(file);
// 				free(formated);
// 				free(fileStr);
// 				return (1);
// 			}

// 			// on cherche la fonction main dans le fichier, s'il n'y en a pas, on pourra agir
// 			noMain = !function_in_prototypes("main", file_prototypes);
// 			if (noMain)
// 			{
// 				fclose(file);
// 				file = fopen(fileStr, "a"); // a pour écrire à la fin
// 				if (file)
// 				{
// 					if (strlen(fileName) > 2 && fileName[strlen(fileName) - 2] == '.' && fileName[strlen(fileName) - 1] == 'c') // pour pouvoir se finir par .c
// 					{
// 						int k = strlen(fileName) - 1;
// 						while (k >= 0 && fileName[k] != '/') // filename contient le chemin absolu du fichier
// 							k --;
// 						k ++;
// 						char	*functionName = malloc(sizeof(char) * (strlen(fileName) - 2 - k + 1));  // on prend a partir du dernier / pour enlever le chemin et -2 pour enlever .c
// 						if (!functionName)
// 						{
// 							fclose(file);
// 							free(formated);
// 							int	nbr_prototypes = 0;
// 							while (file_prototypes[nbr_prototypes])
// 								nbr_prototypes ++;
// 							free_strs(file_prototypes, nbr_prototypes);
// 							free(fileStr);
// 							return (1);
// 						}
						
// 						// par defaut, functionName est le nom du fichier
// 						functionName[strlen(fileName) - 2 - k] = '\0';
// 						int	starting = k;
// 						k = 0;
// 						while (k < strlen(fileName) - 2 - starting)
// 						{
// 							functionName[k] = fileName[k + starting];
// 							k ++;
// 						}

// 						if (function_in_prototypes(functionName, file_prototypes)) // si la fonction existe bien dans le fichier
// 						{
// 							char *prototype = get_prototype_which_name_is(file_prototypes, functionName);
// 							if (!prototype)
// 							{ // prototype in file_prototypes
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);					
// 							}
							
// 							bool chiant = false; // si des tableaux sont à créer manuellement
// 							int nbr_arg = 0;
// 							char	**splited_arg = split(prototype, "()", &nbr_arg);
// 							if (!splited_arg || nbr_arg < 2)
// 							{
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
// 							k = nbr_arg;
// 							char **argsType = split(splited_arg[1], ",", &nbr_arg); // les types des arguments de la fonction (char *, int, etc...)
// 							free_strs(splited_arg, k);
// 							if (!argsType)
// 							{
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
							
// 							int end_return_type = get_name_index(prototype);
// 							char	*sliced_return_type = slice(prototype, 0, end_return_type);
// 							if (!sliced_return_type)
// 							{
// 								free_strs(argsType, nbr_arg);
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
// 							char	**splited_return_type = split(sliced_return_type, " ", &k); // pour enlever l'espace à la fin
// 							free(sliced_return_type);
// 							if (!splited_return_type)
// 							{
// 								free_strs(argsType, nbr_arg);
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
// 							char *return_type = join(splited_return_type, " "); // le type de ce qui est renvoyé par la fonction
// 							free_strs(splited_return_type, k);
// 							if (!return_type)
// 							{
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 								return (1);
// 							}


// 							// on doit connaitre tous les types (retour et arguments) si on veut les créer ou les afficher
// 							bool possible = strstr(return_type, "long") || strstr(return_type, "int") || strstr(return_type, "double") 
// 									|| strstr(return_type, "float") || strstr(return_type, "char") || strstr(return_type, "short");
// 							k = 0;
// 							while (k < nbr_arg && possible)
// 							{
// 								if (!strstr(argsType[k], "long") && !strstr(argsType[k], "int") && !strstr(argsType[k], "double") 
// 									&& !strstr(argsType[k], "float") && !strstr(argsType[k], "char") && !strstr(argsType[k], "short"))
// 									possible = false;
// 								k ++;
// 							}

// 							if (possible)
// 							{
// 								char	**if_strs = get_if_str(argsType, nbr_arg, chiant);
// 								if (!if_strs)
// 								{
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									return (1);
// 								}
// 								char *if_str = if_strs[0];
// 								char *after_if_str = if_strs[1];


								
// 								char	**args_declarations = get_args_declaration_str(argsType, nbr_arg, chiant);
// 								if (!args_declarations)
// 								{
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									return (1);
// 								}
// 								char *args_declarations_str = args_declarations[0];
// 								char *free_var_declaration_str = args_declarations[1];


// 								char *argsStr = get_args_str(argsType, nbr_arg);
// 								if (!argsStr)
// 								{
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									free_strs(args_declarations, 2);
// 									return (1);
// 								}
								
// 								char *printf_str = get_printf_str(formated, return_type, functionName, argsStr);
// 								if (!printf_str)
// 								{
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									free(argsStr);
// 									free_strs(args_declarations, 2);
// 									return (1);
// 								}
								
// 								// char *printf_str = get_return_str(return_type);
// 								// if (!printf_str)
// 								// 	return ;
								
// 								int len_main_str = 50 + strlen(if_str) + strlen(after_if_str) 
// 									+ strlen(free_var_declaration_str) + strlen(args_declarations_str)
// 									+ strlen(printf_str);

// 								char *main_str = malloc(sizeof(char) * (len_main_str + 1));
// 								if (!main_str)
// 								{
// 									free_strs(args_declarations, 2);
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									free(argsStr);
// 									fclose(file);
// 									free(formated);
// 									free(return_type);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									return (1);
// 								}
// 								main_str[len_main_str] = '\0';
// 								len_main_str = 0;
// 								attribute_chars(main_str, "\nint\tmain(int argc, char **argv)\n{\n", 0);
// 								len_main_str += 35;
// 								attribute_chars(main_str, if_str, len_main_str);
// 								len_main_str += strlen(if_str);
// 								attribute_chars(main_str, args_declarations_str, len_main_str);
// 								len_main_str += strlen(args_declarations_str);

// 								attribute_chars(main_str, printf_str, len_main_str);
// 								len_main_str += strlen(printf_str);

// 								attribute_chars(main_str, free_var_declaration_str, len_main_str);
// 								len_main_str += strlen(free_var_declaration_str);
// 								attribute_chars(main_str, after_if_str, len_main_str);
// 								len_main_str += strlen(after_if_str);
// 								attribute_chars(main_str, "\treturn (0);\n", len_main_str);
// 								len_main_str += 13;
// 								attribute_chars(main_str, "}\n", len_main_str);
// 								len_main_str += 2;
								
// 								write(1, "Writing in ", 11);
// 								write(1, fileStr, strlen(fileStr));
// 								write(1, "\n", 1);
							
// 								fprintf(file, "\n%s", main_str);


// 								// on veut afficher un truc du genre 
// 								// les includes
// 								// int main(int argc, char **argv) {
// 								// if_str
// 								// declarations args
// 								// declaration functionName + ( + argsStr + )
// 								// printf_str
// 								// free les déclarations
// 								// after_if_str
// 								// }
// 								// -> args séparés par espace sauf pour tableaux avec [ [] [] ], et on ne gère que des int et char quelque chose ou void

// 								free_strs(args_declarations, 2);
// 								free_strs(if_strs, 2);
// 								free(argsStr);
// 								free(printf_str);
// 								free(main_str);
// 								free(return_type);
// 							}
// 							else
// 							{
// 								write(0, "Bon courage (moi je touche pas à ça (aie des types convenables avant de venir me parler)) :)\n", 96);
// 							}
// 							free_strs(argsType, nbr_arg);
			
// 						}
// 						else
// 							write(0, "Your file should have the name of the function you want to test.\n", 65);
						
// 						free(functionName);
// 					}
// 					else
// 						write(0, "Not a .c file\n", 14);
					
// 					fclose(file);
// 				}
// 				else
// 				{
// 					free(formated);
// 					int	nbr_prototypes = 0;
// 					while (file_prototypes[nbr_prototypes])
// 						nbr_prototypes ++;
// 					free_strs(file_prototypes, nbr_prototypes);
// 					free(fileStr);
				
// 					write(0, "Unable to write in ", 19);
// 					write(0, fileStr, strlen(fileStr));
// 					write(0, "\n", 1);
			
// 				}
// 			}
// 			else
// 				write(0, "Main already present in file\n", 29);
			
// 			free(formated);
// 			int	nbr_prototypes = 0;
// 			while (file_prototypes[nbr_prototypes])
// 				nbr_prototypes ++;
// 			free_strs(file_prototypes, nbr_prototypes);
// 		}
// 		free(fileStr);
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	char	*fileName;
// 	char pwd[1024];
// 	int error_main = 0;

// 	if (argc >= 2)
// 	{
// 		if (getcwd(pwd, sizeof(pwd)) != NULL)
// 		{
// 			if (argc == 3)
// 				fileName
// 			if (argc > 2 && strcmp(argv[2], "man") == 0)
// 				error_main = mainer(pwd, argv[1], true);
// 			else if (argc == 2)
// 				error_main = mainer(pwd, argv[1], false);
// 			else
// 				write(0, "Wtf with the arguments ?\n", 25);
// 			if (error_main)
// 			{
// 				write(0, "Malloc error\n", 13);
// 				return (1);
// 			}
// 		}
// 		else
// 			return (1);
// 	}
// 	return (0);
// }
// 			// on formate le buffer pour les pointeurs et on enlève les commentaires
// 			char *formated = NULL;
// 			formated = formated_buffer(buffer);
// 			free(buffer);
// 			if (!formated)
// 			{
// 				fclose(file);
// 				free(fileStr);
// 				return (1);
// 			}


// 			bool	noMain = false;
// 			char **file_prototypes = get_prototypes(formated);
// 			if (!file_prototypes)
// 			{
// 				fclose(file);
// 				free(formated);
// 				free(fileStr);
// 				return (1);
// 			}

// 			// on cherche la fonction main dans le fichier, s'il n'y en a pas, on pourra agir
// 			noMain = !function_in_prototypes("main", file_prototypes);
// 			if (noMain)
// 			{
// 				fclose(file);
// 				file = fopen(fileStr, "a"); // a pour écrire à la fin
// 				if (file)
// 				{
// 					if (strlen(fileName) > 2 && fileName[strlen(fileName) - 2] == '.' && fileName[strlen(fileName) - 1] == 'c') // pour pouvoir se finir par .c
// 					{
// 						int k = strlen(fileName) - 1;
// 						while (k >= 0 && fileName[k] != '/') // filename contient le chemin absolu du fichier
// 							k --;
// 						k ++;
// 						char	*functionName = malloc(sizeof(char) * (strlen(fileName) - 2 - k + 1));  // on prend a partir du dernier / pour enlever le chemin et -2 pour enlever .c
// 						if (!functionName)
// 						{
// 							fclose(file);
// 							free(formated);
// 							int	nbr_prototypes = 0;
// 							while (file_prototypes[nbr_prototypes])
// 								nbr_prototypes ++;
// 							free_strs(file_prototypes, nbr_prototypes);
// 							free(fileStr);
// 							return (1);
// 						}
						
// 						// par defaut, functionName est le nom du fichier
// 						functionName[strlen(fileName) - 2 - k] = '\0';
// 						int	starting = k;
// 						k = 0;
// 						while (k < strlen(fileName) - 2 - starting)
// 						{
// 							functionName[k] = fileName[k + starting];
// 							k ++;
// 						}

// 						if (function_in_prototypes(functionName, file_prototypes)) // si la fonction existe bien dans le fichier
// 						{
// 							char *prototype = get_prototype_which_name_is(file_prototypes, functionName);
// 							if (!prototype)
// 							{ // prototype in file_prototypes
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);					
// 							}
							
// 							bool chiant = false; // si des tableaux sont à créer manuellement
// 							int nbr_arg = 0;
// 							char	**splited_arg = split(prototype, "()", &nbr_arg);
// 							if (!splited_arg || nbr_arg < 2)
// 							{
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
// 							k = nbr_arg;
// 							char **argsType = split(splited_arg[1], ",", &nbr_arg); // les types des arguments de la fonction (char *, int, etc...)
// 							free_strs(splited_arg, k);
// 							if (!argsType)
// 							{
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
							
// 							int end_return_type = get_name_index(prototype);
// 							char	*sliced_return_type = slice(prototype, 0, end_return_type);
// 							if (!sliced_return_type)
// 							{
// 								free_strs(argsType, nbr_arg);
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
// 							char	**splited_return_type = split(sliced_return_type, " ", &k); // pour enlever l'espace à la fin
// 							free(sliced_return_type);
// 							if (!splited_return_type)
// 							{
// 								free_strs(argsType, nbr_arg);
// 								free(functionName);
// 								fclose(file);
// 								free(formated);
// 								int	nbr_prototypes = 0;
// 								while (file_prototypes[nbr_prototypes])
// 									nbr_prototypes ++;
// 								free_strs(file_prototypes, nbr_prototypes);
// 								free(fileStr);
// 								return (1);
// 							}
// 							char *return_type = join(splited_return_type, " "); // le type de ce qui est renvoyé par la fonction
// 							free_strs(splited_return_type, k);
// 							if (!return_type)
// 							{
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 								return (1);
// 							}


// 							// on doit connaitre tous les types (retour et arguments) si on veut les créer ou les afficher
// 							bool possible = strstr(return_type, "long") || strstr(return_type, "int") || strstr(return_type, "double") 
// 									|| strstr(return_type, "float") || strstr(return_type, "char") || strstr(return_type, "short");
// 							k = 0;
// 							while (k < nbr_arg && possible)
// 							{
// 								if (!strstr(argsType[k], "long") && !strstr(argsType[k], "int") && !strstr(argsType[k], "double") 
// 									&& !strstr(argsType[k], "float") && !strstr(argsType[k], "char") && !strstr(argsType[k], "short"))
// 									possible = false;
// 								k ++;
// 							}

// 							if (possible)
// 							{
// 								char	**if_strs = get_if_str(argsType, nbr_arg, chiant);
// 								if (!if_strs)
// 								{
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									return (1);
// 								}
// 								char *if_str = if_strs[0];
// 								char *after_if_str = if_strs[1];


								
// 								char	**args_declarations = get_args_declaration_str(argsType, nbr_arg, chiant);
// 								if (!args_declarations)
// 								{
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									return (1);
// 								}
// 								char *args_declarations_str = args_declarations[0];
// 								char *free_var_declaration_str = args_declarations[1];


// 								char *argsStr = get_args_str(argsType, nbr_arg);
// 								if (!argsStr)
// 								{
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									free_strs(args_declarations, 2);
// 									return (1);
// 								}
								
// 								char *printf_str = get_printf_str(formated, return_type, functionName, argsStr);
// 								if (!printf_str)
// 								{
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									fclose(file);
// 									free(formated);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									free(return_type);
// 									free(argsStr);
// 									free_strs(args_declarations, 2);
// 									return (1);
// 								}
								
// 								// char *printf_str = get_return_str(return_type);
// 								// if (!printf_str)
// 								// 	return ;
								
// 								int len_main_str = 50 + strlen(if_str) + strlen(after_if_str) 
// 									+ strlen(free_var_declaration_str) + strlen(args_declarations_str)
// 									+ strlen(printf_str);

// 								char *main_str = malloc(sizeof(char) * (len_main_str + 1));
// 								if (!main_str)
// 								{
// 									free_strs(args_declarations, 2);
// 									free_strs(if_strs, 2);
// 									free_strs(argsType, nbr_arg);
// 									free(functionName);
// 									free(argsStr);
// 									fclose(file);
// 									free(formated);
// 									free(return_type);
// 									int	nbr_prototypes = 0;
// 									while (file_prototypes[nbr_prototypes])
// 										nbr_prototypes ++;
// 									free_strs(file_prototypes, nbr_prototypes);
// 									free(fileStr);
// 									return (1);
// 								}
// 								main_str[len_main_str] = '\0';
// 								len_main_str = 0;
// 								attribute_chars(main_str, "\nint\tmain(int argc, char **argv)\n{\n", 0);
// 								len_main_str += 35;
// 								attribute_chars(main_str, if_str, len_main_str);
// 								len_main_str += strlen(if_str);
// 								attribute_chars(main_str, args_declarations_str, len_main_str);
// 								len_main_str += strlen(args_declarations_str);

// 								attribute_chars(main_str, printf_str, len_main_str);
// 								len_main_str += strlen(printf_str);

// 								attribute_chars(main_str, free_var_declaration_str, len_main_str);
// 								len_main_str += strlen(free_var_declaration_str);
// 								attribute_chars(main_str, after_if_str, len_main_str);
// 								len_main_str += strlen(after_if_str);
// 								attribute_chars(main_str, "\treturn (0);\n", len_main_str);
// 								len_main_str += 13;
// 								attribute_chars(main_str, "}\n", len_main_str);
// 								len_main_str += 2;
								
// 								write(1, "Writing in ", 11);
// 								write(1, fileStr, strlen(fileStr));
// 								write(1, "\n", 1);
							
// 								fprintf(file, "\n%s", main_str);


// 								// on veut afficher un truc du genre 
// 								// les includes
// 								// int main(int argc, char **argv) {
// 								// if_str
// 								// declarations args
// 								// declaration functionName + ( + argsStr + )
// 								// printf_str
// 								// free les déclarations
// 								// after_if_str
// 								// }
// 								// -> args séparés par espace sauf pour tableaux avec [ [] [] ], et on ne gère que des int et char quelque chose ou void

// 								free_strs(args_declarations, 2);
// 								free_strs(if_strs, 2);
// 								free(argsStr);
// 								free(printf_str);
// 								free(main_str);
// 								free(return_type);
// 							}
// 							else
// 							{
// 								write(0, "Bon courage (moi je touche pas à ça (aie des types convenables avant de venir me parler)) :)\n", 96);
// 							}
// 							free_strs(argsType, nbr_arg);
			
// 						}
// 						else
// 							write(0, "Your file should have the name of the function you want to test.\n", 65);
						
// 						free(functionName);
// 					}
// 					else
// 						write(0, "Not a .c file\n", 14);
					
// 					fclose(file);
// 				}
// 				else
// 				{
// 					free(formated);
// 					int	nbr_prototypes = 0;
// 					while (file_prototypes[nbr_prototypes])
// 						nbr_prototypes ++;
// 					free_strs(file_prototypes, nbr_prototypes);
// 					free(fileStr);
				
// 					write(0, "Unable to write in ", 19);
// 					write(0, fileStr, strlen(fileStr));
// 					write(0, "\n", 1);
			
// 				}
// 			}
// 			else
// 				write(0, "Main already present in file\n", 29);
			
// 			free(formated);
// 			int	nbr_prototypes = 0;
// 			while (file_prototypes[nbr_prototypes])
// 				nbr_prototypes ++;
// 			free_strs(file_prototypes, nbr_prototypes);
// 		}
// 		free(fileStr);
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	char	*fileName;
// 	char pwd[1024];
// 	int error_main = 0;

// 	if (argc >= 2)
// 	{
// 		if (getcwd(pwd, sizeof(pwd)) != NULL)
// 		{
// 			if (argc == 3)
// 				fileName
// 			if (argc > 2 && strcmp(argv[2], "man") == 0)
// 				error_main = mainer(pwd, argv[1], true);
// 			else if (argc == 2)
// 				error_main = mainer(pwd, argv[1], false);
// 			else
// 				write(0, "Wtf with the arguments ?\n", 25);
// 			if (error_main)
// 			{
// 				write(0, "Malloc error\n", 13);
// 				return (1);
// 			}
// 		}
// 		else
// 			return (1);
// 	}
// 	return (0);
// }