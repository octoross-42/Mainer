/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:25:20 by octoross          #+#    #+#             */
/*   Updated: 2023/05/28 09:28:58 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainer.h"

size_t	file_size(FILE **file)
{
	fseek(*file, 0, SEEK_END);
	long fileLen = ftell(*file);
	rewind(*file);
	return (fileLen);
}
