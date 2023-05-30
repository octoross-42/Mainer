/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionName_of_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:33:09 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:20:05 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

char	*functionName_of_path(char *fileName)
{
	return (substr(fileName, last_occ('/', fileName) + 1, min(last_occ('.', fileName), strlen(fileName))));
}
