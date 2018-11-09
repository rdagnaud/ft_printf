/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdagnaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:04:12 by rdagnaud          #+#    #+#             */
/*   Updated: 2018/11/08 21:44:16 by rdagnaud         ###   ########.fr       */
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

void	add_str_to_data(t_return *all_data)
{
	char	*str_to_add;

	str_to_add = va_arg(all_data->args, char*);
	all_data->ret_str = ft_strcat(all_data->ret_str, str_to_add);
	all_data->ret_val += ft_strlen(str_to_add);
}

void	add_uchar_to_data(t_return *all_data)
{
	int		uchar_to_add;

	uchar_to_add = (unsigned char)va_arg(all_data->args, int);
	all_data->ret_str[all_data->ret_val] = uchar_to_add;
	all_data->ret_str[all_data->ret_val + 1] = '\0';
	all_data->ret_val++;
}

void	add_int_to_data(t_return *all_data)
{
	int		int_to_add;
	char*	str_to_add;

	int_to_add = va_arg(all_data->args, int);
	str_to_add = ft_itoa(int_to_add);
	all_data->ret_str = ft_strcat(all_data->ret_str, str_to_add);
	all_data->ret_val += ft_strlen(str_to_add);
}

void	handle_format(const char *format, t_return *all_data, int *i)
{
	if (format[*i] == 'd' || format[*i] == 'i')
		add_int_to_data(all_data);
	else if (format[*i] == 'c')
		add_uchar_to_data(all_data);
	else if (format[*i] == 's')
		add_str_to_data(all_data);
}

void	handle_flag(const char *format, t_return *all_data, int *i)
{
	handle_format(format, all_data, i);
}

int	check_flags(const char *format, t_return *all_data, int *i)
{
	if (format && all_data)
	{
		if (format[*i] == '%')
		{
			(*i)++;
			handle_flag(format, all_data, i);
			return (1);
		}
	}
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
			add_current_char(all_data, format[i]);
		i++;
	}
	ret = all_data->ret_val;
	last_step(&all_data);
	return (ret);
}

int main(void)
{
	ft_putnbr(ft_printf("bonjour "));
	ft_putchar('\n');
	ft_putnbr(ft_printf("aurevoir "));
	ft_putchar('\n');
	ft_putnbr(ft_printf("lol "));
	ft_putchar('\n');
	ft_putnbr(ft_printf("%d ", 25));
	ft_putchar('\n');
	ft_putnbr(ft_printf("bon%djour ", 13));
	ft_putchar('\n');
	ft_putnbr(ft_printf("%c ", 'e'));
	ft_putchar('\n');
	ft_putnbr(ft_printf("bo%dn%cjo%dur ", 1, '\n', 13));
	ft_putchar('\n');
	ft_putnbr(ft_printf("%s ", "bonjour"));
	ft_putchar('\n');
	ft_putnbr(ft_printf("bon%s ", "jour"));
	ft_putchar('\n');
	return (0);
}
