/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:32:23 by abantari          #+#    #+#             */
/*   Updated: 2025/11/10 20:32:37 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	flags_continue(t_flags *flag, char **format)
{
	if (**format == '.')
	{
		flag->dot = 1;
		(*format)++;
		flag->precision = ft_atoi_pf(format);
		return ;
	}
	else if (ft_isdigit(**format))
	{
		if (flag->dot)
			flag->precision = ft_atoi_pf(format);
		else
			flag->width = ft_atoi_pf(format);
		return ;
	}
	(*format)++;
}

static void	flags(t_flags *flag, char **format)
{
	int	advanced;

	*flag = (t_flags){0};
	while ((**format) && !ft_strchr("csxXudip%", **format))
	{
		advanced = 1;
		if ((**format) == '0')
			flag->zero = 1;
		else if ((**format) == '+')
			flag->plus = 1;
		else if ((**format) == '#')
			flag->hash = 1;
		else if ((**format) == '-')
			flag->minus = 1;
		else if ((**format) == ' ')
			flag->space = 1;
		else
		{
			flags_continue(flag, format);
			advanced = 0;
		}
		if (advanced)
			(*format)++;
	}
}

static void	specifier(va_list *arg, char *format, int *counter, t_flags *flag)
{
	if (*format == 'c')
		flag_char(flag, va_arg(*arg, int), counter);
	else if (*format == 's')
		flag_string(flag, va_arg(*arg, char *), counter);
	else if (*format == 'd' || *format == 'i')
		flag_signed(flag, va_arg(*arg, int), counter);
	else if (*format == 'u')
		flag_unsigned(flag, va_arg(*arg, int), counter);
	else if (*format == 'x')
		flag_x(flag, va_arg(*arg, unsigned int), counter);
	else if (*format == 'X')
		flag_xx(flag, va_arg(*arg, unsigned int), counter);
	else if (*format == 'p')
		flag_adress(flag, va_arg(*arg, void *), counter);
	else if (*format == '%')
		ft_putchar_print('%', counter);
}

int	prinf_suite(char **format, va_list *arg, int *counter, t_flags *flag)
{
	if ((**format) == '%')
	{
		(*format)++;
		if (!(**format))
		{
			va_end(*arg);
			return (-1);
		}
		flags(flag, format);
		specifier(arg, *format, counter, flag);
		(*format)++;
	}
	else
	{
		ft_putchar_print((**format), counter);
		(*format)++;
	}
	return (0);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	arg;
	int		counter;
	t_flags	flag;
	char	*format;

	format = (char *)ptr;
	if (!format)
		return (-1);
	counter = 0;
	va_start(arg, ptr);
	while (*format)
	{
		if (prinf_suite(&format, &arg, &counter, &flag) == -1)
			return (-1);
	}
	va_end(arg);
	return (counter);
}
