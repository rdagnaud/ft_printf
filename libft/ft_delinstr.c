/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delinstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:15:37 by dquartin          #+#    #+#             */
/*   Updated: 2018/03/06 14:21:44 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delinstr(char *src, char *del)
{
	char	*tmp;
	char	*cpy;

	cpy = ft_strstr(src, del) + ft_strlen(del);
	tmp = ft_strsub(src, 0, ft_strstr(src, del) - src);
	tmp = ft_strjoindel(tmp, cpy);
	return (tmp);
}
