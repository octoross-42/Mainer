/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:32:05 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:27:49 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

int	get_to_end_of_block(char *buffer, int start)
//	gets the index of the last character of the function thats starts at index start in buffer
{
	int	nest = 0;
	int	i = start;

	while (buffer[i])
	{
		if (buffer[i] == '{')
			nest ++;
		else if (buffer[i] == '}')
			nest --;

		if (buffer[i] == '}' && nest == 0)
			return (i);
		i ++;
	}
	return (-1);
}

int	get_to_next_block(char *buffer, int i)
// get to next block of the same level we are currently at index
{
	int	nest = 0;
	while (buffer[i])
	{
		if (buffer[i] == '{')
			nest ++;
		
		else if (buffer[i] == '}')
			nest --;

		if (buffer[i] == '{' && nest == 1)
			return (i);
		i ++;
	}
	return (-1);
}

int	moonwalk_to_start_of_functionName(char *buffer, char*functionName, int i)
{
	int endIndex = strlen(functionName) - 1;
	int endBuffer = i;
	//printf("moowalk function : '%s' '%s'\n", &buffer[i], functionName);
	while (i >= 0 && endIndex >= (endBuffer - i) 
		&& buffer[i] == functionName[endIndex - (endBuffer - i)])
		i --;
	i ++;
	if (endIndex == (endBuffer - i) && buffer[i] == functionName[0])
		return (i);
	return (-1);
}

int	get_to_functionName(char *buffer, char *functionName)
// gets the index of the start of the name of the function named functionName in buffer
{
	int	i = 0;
	int	nest = 0;

	while (buffer[i])
	{

		i = get_to_next_block(buffer, i) - 1;
		
		printf("block i : %d '%s'\n", i, &buffer[i]);
		
		if (i < 0)
			return (-1);
		
		while (isspace(buffer[i]))
			i --;
		//printf("alors le moonwalk : '%c' %s\n", buffer[i], &buffer[i]);
		if ((buffer[i] != ')'))
		// also eliminates prototypes
		{
			i = get_to_end_of_block(buffer, i) + 1;
			continue ;
		}
		int parenthesis_nest = 0;
		while (i >= 0)
		{
			//printf("i : %d\n", i);
			if (buffer[i] == '(')
				parenthesis_nest --;
			
			else if (buffer[i] == ')')
				parenthesis_nest ++;
			
			if (buffer[i] == '(' && parenthesis_nest == 0)
				break;
			i --;
		}

		if (buffer[i] == '(' && parenthesis_nest == 0)
		{
			i --;
			while (i >= 0 && isspace(buffer[i]))
				i --;
			if (i > 0) // parce que return type avant au moins
			{
				int	j = moonwalk_to_start_of_functionName(buffer, functionName, i);
				//printf("moowalk : %d\n", i);
				if (j >= 0)
					return (j);

				i = get_to_end_of_block(buffer, i) + 1;
				continue;
			}
		}
		i ++;
	}
	return (-1);
}

int	get_to_start_of_function(char *buffer, char *functionName)
// gets the index of the start of the fonction (not its prototype) which name if functionName in buffer
{
	int	i = get_to_functionName(buffer, functionName);
	// maintenant on va chercher le début du return type
	while (i > 0 && 
		(buffer[i] != ';' && buffer[i] != '}'))
		i --;
	// on revient au debut du return typeif (i < 0)
	while (isspace(buffer[i]))
		i ++;
	return (i);
}

char	*get_function(char *buffer, char *functionName)
// gets the declaration the function called functionName in buffer
{
	int	start = get_to_start_of_function(buffer, functionName);
	printf("start : %d\n", start);
	if (start < 0)
		return (NULL);
	int	end = get_to_end_of_block(buffer, start);
	if (end < 0)
		return (NULL);	
	return (slice(buffer, start, end + 1));
}

bool	is_function_present(char *buffer, char *functionName)
// tests if the declaration of a function called functionName is present in buffer
{
	return (get_to_start_of_function(buffer, functionName) >= 0);
}
