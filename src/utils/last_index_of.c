/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_index_of.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:34:29 by octoross          #+#    #+#             */
/*   Updated: 2023/05/30 10:22:00 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	last_occ(char c, char *str)
{
	int	i = 0;
	int	last_occurrence = -1;

	while (str[i])
	{
		if (str[i] == c)
			last_occurrence = i;
		i ++;
	}
	return (last_occurrence);
}
