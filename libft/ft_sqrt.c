/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:50:46 by dquartin          #+#    #+#             */
/*   Updated: 2017/11/09 10:23:42 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		x;

	x = 1;
	if (nb <= 0)
		return (0);
	while (x <= nb / 2)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}