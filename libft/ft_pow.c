/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:42:06 by dquartin          #+#    #+#             */
/*   Updated: 2017/11/09 11:25:32 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, unsigned int pow)
{
	unsigned int		i;

	i = 0;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		n = n * n;
		i++;
	}
	return (n);
}
