/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:58:24 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 18:30:50 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

bool	c_file(char *fileName)
{
	size_t	len_fileName = strlen(fileName);
	return (len_fileName >= 3 && (fileName[len_fileName - 2] == '.' && fileName[len_fileName - 1] == 'c'));
}
