/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:22:52 by dquartin          #+#    #+#             */
/*   Updated: 2018/03/06 13:55:08 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strintab(char *str, char **stock)
{
	int		i;

	i = 0;
	while (stock[i])
	{
		if (ft_strstr(stock[i], str))
			return (str);
		i++;
	}
	return (NULL);
}
