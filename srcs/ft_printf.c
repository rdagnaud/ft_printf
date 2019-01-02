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

char	*ft_uitoa_base(uintmax_t n, unsigned int base)
{
	char			*new;
	char			*tmp;
	char			*str_base;
	int				i;

	str_base = "0123456789abcdef";
	i = 0;
	new = ft_strnew(1);
	while (n > 0)
	{
		tmp = ft_strjoin(" ", new);
		ft_strdel(&new);
		tmp[i] = str_base[n % base];
		n = n / base;
		new = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (ft_strlen(new) == 0)
	{
		ft_strdel(&new);
		new = ft_strdup("0");
	}
	return (new);
}

void	add_oct_to_data(t_return *all_data)
{
	unsigned int	int_to_add;
	char*			str_to_add;

	int_to_add = va_arg(all_data->args, unsigned int);
	str_to_add = ft_uitoa_base(int_to_add, 8);
	all_data->ret_str = ft_strcat(all_data->ret_str, str_to_add);
	all_data->ret_val += ft_strlen(str_to_add);
}

void	add_hexa_to_data(t_return *all_data, int upcase)
{
	unsigned int	int_to_add;
	char*			str_to_add;

	int_to_add = va_arg(all_data->args, unsigned int);
	str_to_add = ft_uitoa_base(int_to_add, 16);
	if (upcase == 1)
		all_data->ret_str = ft_strcat(all_data->ret_str, ft_touppercase(str_to_add));
	else
		all_data->ret_str = ft_strcat(all_data->ret_str, str_to_add);
	all_data->ret_val += ft_strlen(str_to_add);
}

void	add_hexa_suffixed_to_data(t_return *all_data)
{
	u_int64_t	ptr_to_add;
	char			*str_to_add;
	char			*tmp;

	ptr_to_add = (u_int64_t)va_arg(all_data->args, void*);
	tmp = ft_uitoa_base(ptr_to_add, 16);
	str_to_add = ft_strjoin("0x", tmp);
	all_data->ret_str = ft_strncat(all_data->ret_str, str_to_add, 14);
	all_data->ret_val += ft_strlen(str_to_add) > 14 ? 14 : ft_strlen(str_to_add);
	ft_strdel(&tmp);
}

char	*get_float_digits(double n, int digits)
{
	char	*ret_str;
	int		i;

	i = 0;
	ret_str = malloc(sizeof(char) * (digits + 1));
	while (i < digits)
	{
		n = n * 10;
		ret_str[i] = '0' + (((int)n) % 10);
		i++;
	}
	ret_str[i] = '\0';
	return ret_str;
}

void	add_float_to_data(t_return *all_data)
{
	double	float_to_add;
	char	*str_before_comma;
	char	*str_after_comma;
	int		precision;

	precision = 6;
	float_to_add = va_arg(all_data->args, double);
	str_before_comma = ft_itoa((int)float_to_add);
	str_after_comma = get_float_digits(float_to_add, precision);
	all_data->ret_str = ft_strcat(all_data->ret_str, str_before_comma);
	all_data->ret_str = ft_strcat(all_data->ret_str, ".");
	all_data->ret_str = ft_strcat(all_data->ret_str, str_after_comma);
	all_data->ret_val += ft_strlen(str_before_comma) + ft_strlen(str_after_comma) + 1;
}

void	handle_format(const char *format, t_return *all_data, int *i)
{
	if (format[*i] == 'd' || format[*i] == 'i')
		add_int_to_data(all_data);
	else if (format[*i] == 'c')
		add_uchar_to_data(all_data);
	else if (format[*i] == 's')
		add_str_to_data(all_data);
	else if (format[*i] == 'o')
		add_oct_to_data(all_data);
	else if (format[*i] == 'x' || format[*i] == 'X')
		add_hexa_to_data(all_data, (format[*i] == 'x' ? 0 : 1));
	else if (format[*i] == 'p')
		add_hexa_suffixed_to_data(all_data);
	else if (format[*i] == 'f')
		add_float_to_data(all_data);
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
	int		*i;
	char	*c;

	i = malloc(sizeof(int));
	c = malloc(1);
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
	ft_putnbr(ft_printf("octal: %o hexa: %x", 0, 0));
	ft_putchar('\n');
	ft_putnbr(ft_printf("octal: %o hexa: %x", 9, 9));
	ft_putchar('\n');
	ft_putnbr(ft_printf("octal: %o hexa: %x", 27, 27));
	ft_putchar('\n');
	ft_putnbr(ft_printf("octal: %o HEXA: %X", 27, 27));
	ft_putchar('\n');
	ft_putnbr(ft_printf("octal: %o HEXA: %X", 27, 255));
	ft_putchar('\n');
	ft_putnbr(ft_printf("ptr: %p ", c));
	ft_putchar('\n');
	ft_putnbr(ft_printf("second ptr: %p ", i));
	ft_putchar('\n');
	ft_putnbr(ft_printf("float : %f", 0.36));
	ft_putchar('\n');
	return (0);
}
