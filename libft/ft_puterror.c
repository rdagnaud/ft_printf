/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:56:51 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/11 18:45:31 by rdagnaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrerror(char *s)
{
	ft_putstr_fd(LIGHT_RED, 2);
	write(2, s, ft_strlen(s));
	ft_putstr_fd("\033[0m", 2);
}

int			ft_puterrorint(char *s)
{
	ft_putstr_fd(LIGHT_RED, 2);
	write(2, s, ft_strlen(s));
	ft_putendl_fd("\033[0m", 2);
	return (0);
}

void		ft_puterror(char *s)
{
	ft_putstr_fd(LIGHT_RED, 2);
	write(2, s, ft_strlen(s));
	ft_putendl_fd("\033[0m", 2);
}
