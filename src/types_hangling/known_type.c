/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   known_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:15:42 by octoross          #+#    #+#             */
/*   Updated: 2023/05/29 18:34:29 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

bool	known_type(char *type)
{
	return (strstr(type, "bool") || strstr(type, "size_t") || strstr(type, "long") || strstr(type, "int")
			|| strstr(type, "double") || strstr(type, "float") || strstr(type, "char") || strstr(type, "short"));
}

bool	do_we_know_every_types()
{
	
}
