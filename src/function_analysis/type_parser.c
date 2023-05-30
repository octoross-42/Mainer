// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   type_parser.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/29 17:24:58 by octoross          #+#    #+#             */
// /*   Updated: 2023/05/28 15:10:24 by octoross         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../mainer.h"

// char	**get_if_str(char **argsType, int nbr_arg, bool chiant)
// {
// 	char **if_strs = malloc(sizeof(char *) * 2);
// 	if (!if_strs)
// 		return (NULL);

// 	char *if_str;
// 	char *after_if_str;

// 	if (nbr_arg == 0 || strcmp(argsType[0], "void") == 0)
// 	{
// 		if_str = malloc(sizeof(char));
// 		if (!if_str)
// 		{
// 			free(if_strs);
// 			return (NULL);
// 		}
// 		if_str[0] = '\0';
// 		after_if_str = malloc(sizeof(char));
// 		if (!after_if_str)
// 		{
// 			free(if_str);
// 			free(if_strs);
// 			return (NULL);
// 		}
// 		after_if_str[0] = '\0';
// 	}
// 	else
// 	{
// 		int nbr = nbr_digit(nbr_arg);
// 		if_str = malloc(sizeof(char) * (18 + nbr));
// 		if (!if_str)
// 		{
// 			free(if_strs);
// 			return (NULL);
// 		}
// 		if_str[17 + nbr] = '\0';
		
// 		attribute_chars(if_str, "\tif (argc > ", 0);
// 		char *itoa;
// 		if (chiant)
// 		{
// 			itoa = NULL;
// 		}
// 		else
// 			itoa = malloc(sizeof(char) * (nbr + 1));
// 		if (!itoa)
// 		{
// 			free(if_str);
// 			free(after_if_str);
// 			free(if_strs);
// 			return (NULL);
// 		}
// 		sprintf(itoa, "%d", nbr_arg);
// 		attribute_chars(if_str, itoa, 12);
// 		attribute_chars(if_str, ")\n\t{\n", 12 + nbr);
// 		free(itoa);

// 		after_if_str = malloc(sizeof(char) * 4);
// 		if (!after_if_str)
// 		{
// 			free(if_str);
// 			free(if_strs);
// 			return (NULL);
// 		}
// 		after_if_str[3] = '\0';
// 		attribute_chars(after_if_str, "\t}\n", 0);
// 	}

// 	if_strs[0] = if_str;
// 	if_strs[1] = after_if_str;
// 	return (if_strs);
// }


// char	**get_args_declaration_str(char **argsType, int nbr_arg, bool chiant)
// {
// 	int	len_declaration = 0;
// 	int len_free = 0;
// 	int	i = 0;
// 	if (chiant)
// 	{

// 	}
// 	else
// 	{
// 		while (i < nbr_arg)
// 		{
// 			if ((strstr(argsType[i], "*") && !strstr(argsType[i], "char")) || (strstr(argsType[i], "**") && strstr(argsType[i], "char")))
// 			{
// 				len_free += 0;
// 				return (NULL);
// 			}
// 			else // on peut directement déclarer la variable
// 			{
// 				// int atoi + "" = argv[];"
// 				int len_transformation = 0;
// 				char **splited_type = split(argsType[i], " ", &len_transformation);
// 				if (!splited_type)
// 					return (NULL);
// 				char *arg_type = join_until(splited_type, " ", len_transformation - 1);
// 				free_strs(splited_type, len_transformation);
// 				if (!arg_type)
// 					return (NULL);
				
// 				if (!strcmp(arg_type, "char *"))
// 					len_transformation = 0;
// 				else if (!(strcmp(arg_type, "int")
// 							&& strcmp(arg_type, "short int") && strcmp(arg_type, "short")
// 							&& strcmp(arg_type, "long") && strcmp(arg_type, "long int")
// 							&& strcmp(arg_type, "float")
// 							&& strcmp(arg_type, "double")))
// 					// atoi() ou atoil() ou strtof ou strtod
// 					len_transformation = 6;
// 				else if (!strcmp(arg_type, "long long"))
// 					// atoll()
// 					len_transformation = 7;
		
// 				else if (!(strcmp(arg_type, "unsigned long") && strcmp(arg_type, "unsigned long int") && strcmp(arg_type, "unsigned int")
// 							&& strcmp(arg_type, "unsigned short int") && strcmp(arg_type, "unsigned short")
// 							&& strcmp(arg_type, "long double")))
// 					// strtoul() ou strtold()
// 					len_transformation = 9;
// 				else if (!strcmp(arg_type, "unsigned long long"))
// 					// strtoull()
// 					len_transformation = 10;
// 				else if (!(strcmp(arg_type, "char") && strcmp(arg_type, "unsigned char")))
// 				// [0]
// 					len_transformation = 3;
				
// 				if (strstr(arg_type, "*"))
// 					len_transformation --;
// 				len_declaration += 13 + nbr_digit(i + 1) + len_transformation + strlen(argsType[i]);
// 				free(arg_type);
// 			}
// 			i ++;
// 		}
// 		char *args_declarations = malloc(sizeof(char) * (len_declaration + 1));
// 		if (!args_declarations)
// 			return (NULL);
// 		args_declarations[len_declaration] = '\0';
// 		char *args_free = malloc(sizeof(char) * (len_free + 1));
// 		if (!args_free)
// 		{
// 			free(args_declarations);
// 			return (NULL);
// 		}
// 		args_free[len_free] = '\0';
// 		i = 0;
// 		len_declaration = 0;
// 		while (i < nbr_arg)
// 		{
// 			if ((strstr(argsType[i], "*") && !strstr(argsType[i], "char")) || (strstr(argsType[i], "**") && strstr(argsType[i], "char")))
// 			{
// 				return (NULL);
// 			}
// 			else // on peut directement déclarer la variable
// 			{
// 				int len_transformation = 0;
				
// 				char *itoa = malloc(sizeof(char) * (nbr_digit(i + 1) + 1));
// 				if (!itoa)
// 				{
// 					free(args_declarations);
// 					return (NULL);
// 				}
// 				itoa[nbr_digit(i + 1)] = '\0';
// 				sprintf(itoa, "%d", i + 1);

// 				char **splited_type = split(argsType[i], " ", &len_transformation);
// 				if (!splited_type)
// 					return (NULL);
// 				char *arg_type = join_until(splited_type, " ", len_transformation - 1);
// 				if (!arg_type)
// 					return (NULL);
				
				
// 				attribute_chars(args_declarations, "\t\t", len_declaration);
// 				attribute_chars(args_declarations, arg_type, len_declaration + 2);
// 				len_declaration += 2 + strlen(arg_type);
// 				if (!strstr(arg_type, "*"))
// 				{
// 					attribute_chars(args_declarations, " ", len_declaration);
// 					len_declaration ++;
// 				}
// 				attribute_chars(args_declarations, splited_type[len_transformation - 1], len_declaration);
// 				len_declaration += strlen(splited_type[len_transformation - 1]);
// 				attribute_chars(args_declarations, " = ", len_declaration);
// 				len_declaration += 3;
// 				free_strs(splited_type, len_transformation);
				
// 				if (!strcmp(arg_type, "char *"))
// 				{
// 					attribute_chars(args_declarations, "argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 5);
// 					attribute_chars(args_declarations, "];\n", len_declaration + 5 + nbr_digit(i + 1));
// 					len_transformation = 0;
// 				}
// 				else if (!(strcmp(arg_type, "int")
// 							&& strcmp(arg_type, "short int") && strcmp(arg_type, "short")))
// 					// atoi()
// 				{
// 					len_transformation = 6;
// 					attribute_chars(args_declarations, "atoi(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!(strcmp(arg_type, "long") && strcmp(arg_type, "long int")))
// 				{
// 					// atol()
// 					len_transformation = 6;
// 					attribute_chars(args_declarations, "atol(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!strcmp(arg_type, "float"))
// 				{
// 					// strtof()
// 					len_transformation = 6;
// 					attribute_chars(args_declarations, "strtof(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!strcmp(arg_type, "double"))
// 				{
// 					//strtod()
// 					len_transformation = 6;
// 					attribute_chars(args_declarations, "strtod(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!strcmp(arg_type, "long long"))
// 				{
// 					// atoll()
// 					len_transformation = 7;
// 					attribute_chars(args_declarations, "atoll(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!(strcmp(arg_type, "unsigned long") && strcmp(arg_type, "unsigned long int") && strcmp(arg_type, "unsigned int")
// 							&& strcmp(arg_type, "unsigned short int") && strcmp(arg_type, "unsigned short")))
// 					// strtoul()
// 				{
// 					len_transformation = 9;
// 					attribute_chars(args_declarations, "strtoul(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!strcmp(arg_type, "long double"))
// 				{
// 					// strtold()
// 					len_transformation = 9;
// 					attribute_chars(args_declarations, "strtold(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!strcmp(arg_type, "unsigned long long"))
// 				{
// 					// strtoull()
// 					len_transformation = 10;
// 					attribute_chars(args_declarations, "strtoull(argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 4 + len_transformation);
// 					attribute_chars(args_declarations, "]);\n", len_declaration + 4 + len_transformation + nbr_digit(i + 1));
// 				}
// 				else if (!(strcmp(arg_type, "char") && strcmp(arg_type, "unsigned char")))
// 				{
// 					attribute_chars(args_declarations, "argv[", len_declaration);
// 					attribute_chars(args_declarations, itoa, len_declaration + 5);
// 					attribute_chars(args_declarations, "][0];\n", len_declaration + 5 + nbr_digit(i + 1));
// 					len_transformation = 3;
// 				}
				
				
// 				len_declaration += 8 + nbr_digit(i + 1) + len_transformation;
// 				free(itoa);
// 				free(arg_type);
// 			}
// 			i ++;
// 		}

// 		char **args_declarationss = malloc(sizeof(char *) * 2);
// 		if (!args_declarationss)
// 		{
// 			free(args_declarations);
// 			free(args_free);
// 			return (NULL);
// 		}
// 		args_declarationss[0] = args_declarations;
// 		args_declarationss[1] = args_free;
// 		return (args_declarationss);
// 	}
// }

// char	*get_args_str(char **argsType, int nbr_arg)
// {
// 	int	len = 0;
// 	int i = 0;
// 	int len_split = 0;
// 	while (i < nbr_arg)
// 	{
// 		char **splited = split(argsType[i], " ", &len_split);
// 		if (!splited)
// 			return (NULL);
// 		len += strlen(splited[len_split - 1]);
// 		free_strs(splited, len_split);
// 		if (i + 1 < nbr_arg)
// 			len += 2;
// 		i ++;
// 	}
// 	char *argsStr = malloc(sizeof(char) * (len + 1));
// 	if (!argsStr)
// 		return (NULL);
// 	argsStr[len] = '\0';
// 	len = 0;
// 	i = 0;
// 	while (i < nbr_arg)
// 	{
// 		char **splited = split(argsType[i], " ", &len_split);
// 		if (!splited)
// 			return (NULL);
// 		attribute_chars(argsStr, splited[len_split - 1], len);
// 		len += strlen(splited[len_split - 1]);
// 		free_strs(splited, len_split);
// 		if (i + 1 < nbr_arg)
// 		{
// 			attribute_chars(argsStr, ", ", len);
// 			len += 2;
// 		}
// 		i ++;
// 	}
// 	return (argsStr);
// }

// bool	already_used(char c, char *argsStr)
// {
// 	return (false);
// }

// int	len_printf_format(const char *return_type)
// {
// 	int i = 0;
// 	while (return_type[i] && return_type[i] != '*')
// 		i ++;
// 	if (return_type[i] == '*' && !strstr(return_type, "char"))
// 		i --;
// 	else if (return_type[i] == '*')
// 		i ++;
// 	char *return_abrege = malloc(sizeof(char) * (i + 1));
// 	if (!return_abrege)
// 		return (-1);
// 	return_abrege[i] = '\0';
// 	int j = 0;
// 	while (j < i)
// 	{
// 		return_abrege[j] = return_type[j];
// 		j ++;
// 	}
// 	int len = 0;
// 	if (!(strcmp(return_abrege, "char *")))
// 		// 	%s
// 		len = 1;
// 	else if (!(strcmp(return_abrege, "char")))
// 		// 	%c
// 		len = 1;
// 	else if (!(strcmp(return_abrege, "unsigned char")))
// 		// 	%c
// 		len = 1;
// 	else if (!(strcmp(return_abrege, "int")))
// 		// 	d
// 		len = 1;
// 	else if (!(strcmp(return_abrege, "float")))
// 		// 	%f
// 		len = 1;
// 	else if (!(strcmp(return_abrege, "double")))
// 		// 	%e
// 		len = 1;
// 	else if (!(strcmp(return_abrege, "short") && strcmp(return_abrege, "short int")))
// 		// 	%hd
// 		len = 2;
// 	else if (!(strcmp(return_abrege, "long") && strcmp(return_abrege, "long int")))
// 		// 	%ld
// 		len = 2;
// 	else if (!(strcmp(return_abrege, "unsigned int")))
// 		// 	%u
// 		len = 1;
// 	else if (!(strcmp(return_abrege, "unsigned long") && strcmp(return_abrege, "unsigned long int")))
// 		// 	%lu
// 		len = 2;
// 	else if (!(strcmp(return_abrege, "unsigned short") && strcmp(return_abrege, "unsigned short int")))
// 		// 	%hu
// 		len = 2;
// 	else if (!(strcmp(return_abrege, "long long")))
// 		// 	%lld
// 		len = 3;
// 	else if (!(strcmp(return_abrege, "unsigned long long")))
// 		// 	%llu
// 		len = 3;
// 	else if (!(strcmp(return_abrege, "long double")))
// 		// 	%Le
// 		len = 2;
	
// 	free(return_abrege);
// 	return (len);
// }

// char	*printf_format(const char *return_type)
// {
// 	int i = 0;
// 	while (return_type[i] && return_type[i] != '*')
// 		i ++;
// 	if (return_type[i] == '*' && !strstr(return_type, "char"))
// 		i --;
// 	else if (return_type[i] == '*')
// 		i ++;
// 	char *return_abrege = malloc(sizeof(char) * (i + 1));
// 	if (!return_abrege)
// 		return (NULL);
// 	return_abrege[i] = '\0';

// 	int j = 0;
// 	while (j < i)
// 	{
// 		return_abrege[j] = return_type[j];
// 		j ++;
// 	}
// 	int len_format = len_printf_format(return_type);
// 	if (len_format < 0)
// 	{
// 		free(return_abrege);
// 		return (NULL);
// 	}

// 	char *format = malloc(sizeof(char) * (len_format+ 1));
// 	if (!format)
// 	{
// 		free(return_abrege);
// 		return (NULL);
// 	}
// 	format[len_format] = '\0';
// 	if (!(strcmp(return_abrege, "char *")))
// 		// 	%s
// 		format[0] =  's';
// 	else if (!(strcmp(return_abrege, "char")))
// 		// 	%c
// 		format[0] =  'c';
// 	else if (!(strcmp(return_abrege, "unsigned char")))
// 		// 	%c
// 		format[0] =  'c';
// 	else if (!(strcmp(return_abrege, "int")))
// 		// 	d
// 		format[0] =  'd';
// 	else if (!(strcmp(return_abrege, "float")))
// 		// 	%f
// 		format[0] =  'f';
// 	else if (!(strcmp(return_abrege, "double")))
// 		// 	%e
// 		format[0] =  'e';
// 	else if (!(strcmp(return_abrege, "short") && strcmp(return_abrege, "short int")))
// 		// 	%hd
// 		format[0] =  'h';
// 	else if (!(strcmp(return_abrege, "long") && strcmp(return_abrege, "long int")))
// 		// 	%ld
// 	{
// 		format[0] =  'l';
// 		format[1] =  'd';
// 	}
// 	else if (!(strcmp(return_abrege, "unsigned int")))
// 		// 	%u
// 		format[0] =  'u';
// 	else if (!(strcmp(return_abrege, "unsigned long") && strcmp(return_abrege, "unsigned long int")))
// 		// 	%lu
// 	{
// 		format[0] =  'l';
// 		format[1] =  'u';
// 	}
// 	else if (!(strcmp(return_abrege, "unsigned short") && strcmp(return_abrege, "unsigned short int")))
// 		// 	%hu
// 	{
// 		format[0] =  'h';
// 		format[1] =  'u';
// 	}
// 	else if (!(strcmp(return_abrege, "long long")))
// 		// 	%lld
// 	{
// 		format[0] =  'l';
// 		format[1] =  'l';
// 		format[2] =  'd';
// 	}
// 	else if (!(strcmp(return_abrege, "unsigned long long")))
// 		// 	%llu
// 	{
// 		format[0] =  'l';
// 		format[1] =  'l';
// 		format[2] =  'u';
// 	}
// 	else if (!(strcmp(return_abrege, "long double")))
// 		// 	%Le
// 	{
// 		format[0] =  'L';
// 		format[1] =  'e';
// 	}
// 	free(return_abrege);
// 	return (format);
// }



// int	write_while(int index_while, int nbr_while, char *printf_str, int *len_str, int *deja_pris, char *argsStr, char *return_type)
// {
// 	char	increments[27] = { 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'h', '\0'};

// 	if (nbr_while > 0)
// 	{
// 		attribute_chars(printf_str, "\t\t", (*len_str));
// 		(*len_str) += 2;

// 		int x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}

// 		attribute_chars(printf_str, "int ", (*len_str));
// 		(*len_str) += 4;
		
// 		printf_str[*len_str] = increments[index_while];
// 		(*len_str) ++;
		
// 		attribute_chars(printf_str, " = 0;\n", (*len_str));
// 		(*len_str) += 6;



// 		// \t\tprintf("[ ");

// 		x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}

// 		attribute_chars(printf_str, "\t\tprintf(", (*len_str));
// 		(*len_str) += 9;
// 		printf_str[*len_str] = '"';
// 		(*len_str) ++;
// 		attribute_chars(printf_str, "[ ", (*len_str));
// 		(*len_str) += 2;
// 		printf_str[*len_str] = '"';
// 		(*len_str) ++;
// 		attribute_chars(printf_str, ");\n", (*len_str));
// 		(*len_str) += 3;

// 		x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}
// 		attribute_chars(printf_str, "\t\twhile (", (*len_str));
// 		(*len_str) += 9; // \t\twhile (

// 		if (strstr(return_type, "char"))
// 		{
// 			attribute_chars(printf_str, "return_type", (*len_str));
// 			(*len_str) += 11; // return_type[i][j][k]...; 2 * (index_while + 1) + sum(i / 26) i = 0 a index_while
// 			int l = 0;
// 			while (l <= index_while)
// 			{
// 				attribute_chars(printf_str, "[", (*len_str));
// 				(*len_str) ++;
// 				printf_str[*len_str] = increments[l];
// 				(*len_str) ++;
// 				attribute_chars(printf_str, "]", (*len_str));
// 				(*len_str) ++;
// 				l ++;
// 			}
// 		}
		
// 		else
// 			return (1);
// 			//(*len_str) += ;

// 		attribute_chars(printf_str, ")\n", (*len_str));
// 		(*len_str) += 2; // )\n

// 		x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}
// 		attribute_chars(printf_str, "\t\t{\n", (*len_str));
// 		(*len_str) += 4; // \t\t{\n
// 	}
	
	
// 	if (index_while + 1 < nbr_while)
// 	{
// 		int error = write_while(index_while + 1, nbr_while, printf_str, len_str, deja_pris, argsStr, return_type);
// 		if (error)
// 			return (1);
// 	}
// 	else
// 	{
// 		// (2 + nbr_while) + 28 + nbr_while * 3
		
// 		int x = 0;
// 		if (nbr_while > 0)
// 		{
// 			while (x <= index_while)
// 			{
// 				attribute_chars(printf_str, "\t", *len_str);
// 				(*len_str) ++;
// 				x ++;
// 			}
// 		}
		
// 		// \t\t printf("%\n", return_type[i][j]);
// 		attribute_chars(printf_str, "\t\tprintf(", *len_str);
// 		(*len_str) += 9;
// 		printf_str[*len_str] = '"';
// 		(*len_str) ++;
// 		printf_str[*len_str] = '%';
// 		(*len_str) ++;

// 		char *format = printf_format(return_type);
// 		if (!format)
// 			return (1);
// 		attribute_chars(printf_str, format, (*len_str));
// 		(*len_str) += strlen(format);
// 		free(format);
		
// 		attribute_chars(printf_str, " ", (*len_str));
// 		(*len_str) ++ ;
// 		printf_str[*len_str] = '"';
// 		(*len_str) ++;
// 		attribute_chars(printf_str, ", return_type", (*len_str));
// 		(*len_str) += 13;
		
// 		if (nbr_while > 0)
// 		{
// 			x = 0;
// 			while (x <= index_while)
// 			{
// 				printf_str[*len_str] = '[';
// 				(*len_str) ++;
// 				printf_str[*len_str] = increments[x];
// 				(*len_str) ++;
// 				printf_str[*len_str] = ']';
// 				(*len_str) ++;
// 				x ++;
// 			}
// 		}
		
// 		attribute_chars(printf_str, ");\n", (*len_str));
// 		(*len_str) += 3;

// 	}

// 	if (nbr_while > 0)
// 	{
// 		// (3 + nbr_while) + 19 + 3 * (nbr_while + 1)
// 		int x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}
// 		attribute_chars(printf_str, "\t\t\tfree(return_type", (*len_str));
// 		(*len_str) += 19;
// 		x = 0;
// 		while (x <= index_while)
// 		{
// 			printf_str[*len_str] = '[';
// 			(*len_str) ++;
// 			printf_str[*len_str] = increments[x];
// 			(*len_str) ++;
// 			printf_str[*len_str] = ']';
// 			(*len_str) ++;
		
// 			x ++;
// 		}
// 		attribute_chars(printf_str, ");\n", (*len_str));
// 		(*len_str) += 3;
		


// 		x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}
// 		attribute_chars(printf_str, "\t\t\t", (*len_str));
// 		(*len_str) += 3;
// 		printf_str[*len_str] = increments[index_while];
// 		(*len_str) ++;
// 		attribute_chars(printf_str, " ++;\n", (*len_str));
// 		(*len_str) += 5; // i ++;\n;
		
// 		x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}
// 		attribute_chars(printf_str, "\t\t}\n", (*len_str));		
// 		(*len_str) += 4; // \t\t}\n


// 		// \t\tprintf("] /\n");
// 		x = 0;
// 		while (x < index_while)
// 		{
// 			attribute_chars(printf_str, "\t", (*len_str));
// 			(*len_str) ++;
// 			x ++;
// 		}

// 		attribute_chars(printf_str, "\t\tprintf(", (*len_str));
// 		(*len_str) += 9;
// 		printf_str[*len_str] = '"';
// 		(*len_str) ++;
// 		if (index_while == 0)
// 		{
// 			attribute_chars(printf_str, "]\\n", (*len_str));
// 			(*len_str) ++;
// 		}
// 		else
// 			attribute_chars(printf_str, "] ", (*len_str));
			
// 		(*len_str) += 2;
// 		printf_str[*len_str] = '"';
// 		(*len_str) ++;
// 		attribute_chars(printf_str, ");\n", (*len_str));
// 		(*len_str) += 3;
		
// 	}
// 	return (0);
// }


// char	*get_printf_str(char *formated, char *return_type, char *functionName, char *argsStr)
// {	
// 	char	**returns = get_return_insides(formated, functionName);
// 	if (!returns)
// 		return (NULL);
// 	int h = 0;
// 	while (returns[h])
// 	{
// 		printf("returns : %s\n", returns[h]);
// 		free(returns[h]);
// 		h ++;
// 	}
// 	free(returns);

// 	char	*size_alloc = find_return_sizes(return_type, functionName, formated);
// 	printf("test : %s\n", size_alloc);
// 	free(size_alloc);


// 	int len_str = 0;
// 	if (strcmp(return_type, "void"))
// 		len_str += 2 + strlen(return_type) + 14; // \t\t char *return_type = 
// 	if (!strstr(return_type, "*"))
// 		len_str ++;
// 	len_str += 4 + strlen(functionName) + strlen(argsStr); // ft_atoi(argsStr);\n

// 	int	nbr_while = 0;
// 	int nbr_char = 0;
// 	if ((strstr(return_type, "*") && !strstr(return_type, "char")) || (strstr(return_type, "**") && strstr(return_type, "char")))
// 	{
// 		bool first_time_char = strstr(return_type, "char");
// 		bool first_loop = true;
// 		int i = 0;
// 		while (return_type[i])
// 		{
// 			if (return_type[i] == '*')
// 			{
// 				if (!first_time_char)
// 				{
// 					len_str += 2 + nbr_while + 11; // \t\t + (\t * nbr_while) int i = 0;
// 					len_str += 2 + nbr_while + 14; // \t\tprintf("[ ");
// 					if (first_loop)
// 					{
// 						len_str += 2 + nbr_while + 15; // \t\tprintf("]\n");
// 						first_loop = false;
// 					}
// 					else 
// 						len_str += 2 + nbr_while + 14; // \t\tprintf("] ");

// 					len_str += 2 + nbr_while + 9; // \t\t + (\t * nbr_while) + while ()\n
// 					if (strstr(return_type, "char"))
// 						len_str += 11 + 3 * (nbr_while + 1); // return_type[i][j][k]...; 2 * (nbr_while + 1) + sum(i / 26) i = 0 a nbr_while
					
// 					else
// 						return (NULL);
// 						//len_str += ;
// 					len_str += (4 + nbr_while) * 2; // \t\t + (\t * nbr_while){ / }\n
// 					len_str += (3 + nbr_while) + 19 + 3 * (nbr_while + 1); // \t\t + (\t * nbr_while) free(return_type[i][j]);
// 					len_str += (3 + nbr_while) + 6; // \t\t + (\t * nbr_while) i ++;

// 					nbr_while ++;
// 				}
// 				else
// 					first_time_char = false;
// 			}
// 			i ++;
// 		}
// 	}
// 	if (nbr_while > 26)
// 	{
// 		write(0, "Why autant de boucles\n", 22);
// 		return (NULL);
// 	}
// 	int len_format = len_printf_format(return_type);
// 	if (len_format < 0)
// 		return (NULL);
// 	// \t\t\tprintf("% ", return_type[i][j]);
// 	len_str += (2 + nbr_while) + 27 + nbr_while * 3 + len_format;

// 	if (strstr(return_type, "*"))
// 		len_str += 21; // \t\tfree(return_type);

// 	char *printf_str = malloc(sizeof(char) * (len_str + 1));
// 	if (!printf_str)
// 		return (NULL);
// 	printf_str[len_str] = '\0';
	
// 	len_str = 0;
// 	attribute_chars(printf_str, "\t\t", len_str);
// 	len_str += 2;
	
	
// 	if (strcmp(return_type, "void"))
// 	{
// 		attribute_chars(printf_str, return_type, len_str);
// 		len_str += strlen(return_type);
// 		if (!strstr(return_type, "*"))
// 		{
// 			attribute_chars(printf_str, " ", len_str);
// 			len_str ++;
// 		}
// 		attribute_chars(printf_str, "return_type = ", len_str);
// 		len_str += 14;
// 	}

// 	attribute_chars(printf_str, functionName, len_str);
// 	len_str += strlen(functionName);
// 	attribute_chars(printf_str, "(", len_str);
// 	len_str += 1;
// 	attribute_chars(printf_str, argsStr, len_str);
// 	len_str += strlen(argsStr);
// 	attribute_chars(printf_str, ");\n", len_str);
// 	len_str += 3;

// 	int	deja_pris = 0;
// 	int	index_while = 0;

// 	int error = write_while(index_while, nbr_while, printf_str, &len_str, &deja_pris, argsStr, return_type);
// 	if (error)
// 		return (NULL);

// 	if (strstr(return_type, "*"))
// 		attribute_chars(printf_str, "\t\tfree(return_type);\n", len_str); // \t\tfree(return_type);
		
// 	return (printf_str);
// }

// // int	main(int argc, char **argv)
// // {
// // 	if (argc > 1)
// // 	{
// // 		char *s = printf_format(argv[1]);
// // 		printf("print format : %s\n", s);
// // 		free(s);
// // 	}
// // 	return (0);
// // }