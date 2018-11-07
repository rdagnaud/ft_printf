/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:03:53 by dquartin          #+#    #+#             */
/*   Updated: 2018/05/23 13:36:24 by rdagnaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + 48);
		}
		if (n < 10)
			ft_putchar(n % 10 + 48);
	}
}

void	ft_putnbr_max(intmax_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_max(n / 10);
		ft_putchar(n % 10 + 48);
	}
	if (n < 10)
		ft_putchar(n % 10 + 48);
}
