/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdagnaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:04:12 by rdagnaud          #+#    #+#             */
/*   Updated: 2018/10/06 22:52:09 by rdagnaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_return	*init_struct_all_data(void)
{
	t_return	*all_data;

	if (!(all_data = (t_return *)malloc(sizeof(t_return))))
		return (NULL);
	all_data->ret_val = 0;
	all_data->ret_str = ft_strnew(1000);
	return (all_data);
}

void	last_step(t_return **all_data)
{
	ft_putstr((*all_data)->ret_str);
	va_end((*all_data)->args);
	ft_strdel(&((*all_data)->ret_str));
	free(*all_data);
}

int	check_flags(const char *format, t_return *all_data, int *i)
{
	if (format && all_data && (*i) + 1)
		return (0);
	return (0);
}

void	add_current_char(t_return *all_data, char c)
{
	if (all_data->ret_val + 1 % 1000 == 0)
		ft_realloc(all_data->ret_str, all_data->ret_val + 1, all_data->ret_val + 1001);
	all_data->ret_str[all_data->ret_val] = c;
	all_data->ret_val++;
}

int	ft_printf(const char *format, ...)
{
	t_return	*all_data;
	int			i;
	int			ret;

	if (!(all_data = init_struct_all_data()))
		return (-1);
	va_start(all_data->args, format);
	i = 0;
	while (format[i])
	{
		if (!(check_flags(format, all_data, &i)))
		{
			add_current_char(all_data, format[i]);
		}
		i++;
	}
	ret = all_data->ret_val;
	last_step(&all_data);
	return (ret);
}

int main(void)
{
	ft_putnbr(ft_printf("bonjour"));
	ft_putnbr(ft_printf("aurevoir"));
	ft_putnbr(ft_printf("lol"));
	return (0);
}
