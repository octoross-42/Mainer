/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:56:17 by octoross          #+#    #+#             */
/*   Updated: 2023/05/25 19:56:30 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

int	depth_of(char *type)
{
	int	occ = nbr_occ('*', type);
	if (occ > 0 && (strstr(type, "char") || strstr(type, "void")))
		return (occ - 1);
	return (occ);
}
