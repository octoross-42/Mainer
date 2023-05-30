/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:01:22 by octoross          #+#    #+#             */
/*   Updated: 2023/05/22 20:01:27 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nbr_digit(unsigned int n)
{
	int nbr = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		nbr ++;
	}
	return (nbr);
}
