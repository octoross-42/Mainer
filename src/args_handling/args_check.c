/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:09:46 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 18:44:56 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../mainer.h"

// int	check_array(char *args, int i, args_opts opt, int depth)
// // check si un array dans args à partir de l'indice i est un arg correct et renvoie son indice de fin
// {
// 	int	nest = 0;
// 	// soit on rentre dans un tableau soit c'est null
// 	while (isspace(args[i]))
// 		i ++;
// 	if (args[i] == opt.args_in)
// 	{
// 		i ++;
// 		nest ++;
// 		bool we_re_in = true;
// 		while (args[i] && we_re_in)
// 		{
// 			if (args[i] == opt.args_in)
// 			{
// 				nest ++;
// 				if (nest > depth)
// 					return (-1);
// 			}
// 			else if (args[i] == opt.args_out)
// 			{
// 				nest --;
// 				if (nest < 0)
// 					return (-1);
// 				if (nest == 0)
// 					we_re_in = false;
// 			}
// 			else if (!isspace(args[i]))
// 			{
// 				if (nest != depth)
// 					return (-1);
// 			}
// 			i ++;
// 		}
// 	}
// 	else if (strlen(args) - i >= 4 && 
// 		(args[i] == 'N' && args[i + 1] == 'U' && args[i + 2] == 'L' && args[i + 3] == 'L'))
// 		i += 4;
// 	return (i);
// }

// int	check_notarray(char *args, int i, args_opts opt)
// // check si un arg simple (pas un tableau autre que str) dans args à partir de l'indice i est un arg correct et renvoie son indice de fin
// {
// 	int	in_str = false;
// 	while (isspace(args[i]))
// 		i ++;
// 	if (args[i] == opt.args_container)
// 	{
// 		while (args[i] && args[i] != opt.args_container)
// 			i ++;

// 		if (!args[i] == opt.args_container)
// 			return (-1);
// 	}
// 	return (i);
// }


// int	mainer_args(int argc, char **argv, int nbr_args, char **args_types) // à changer -> stocker nbr_args et args_types quelque part
// //	checke si une chaine de caractère représente une liste d'arguments valides pour une liste de types attendus
// {
// 	// pour l'instant on n'implémente pas le ... parce que trop chiant on fera ça après
// 	if (argc < 0 || !argv || !args_types)
// 		return (-1);
// 	int	i = 0;
// 	int	args_types_index = 0;
// 	while (args_types[args_types_index])
// 	{
// 		int depth = depth_of(args_types[args_types_index]);
// 		if (depth > 0)
// 		{
// 			i = check_array(args, i, opt, depth);
// 			if (i < 0)
// 				return (0);
// 		}
// 		else
// 		{
// 			i = check_notarray(args, i, opt);
// 			if (i < 0)
// 				return (0);
// 		}
// 		args_types_index ++;
// 	}
// 	while (isspace(args[i]))
// 		i ++;
// 	if (args[i])
// 	// t'es pas censé être là frérot
// 		return (0);
// 	return (1);
// }

