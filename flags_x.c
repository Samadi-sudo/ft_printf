/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:26:48 by abantari          #+#    #+#             */
/*   Updated: 2025/11/13 17:26:50 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prefix_x(t_flags *flag, int *counter)
{
	if (flag->hash)
	{
		ft_putchar_print('0', counter);
		ft_putchar_print('x', counter);
	}
}

static void	pading_char_x(t_flags *flag, int *counter)
{
	if (flag->zero && !flag->dot)
	{
		if (flag->hash)
			prefix_x(flag, counter);
		while (flag->width > 0)
		{
			ft_putchar_print('0', counter);
			flag->width--;
		}
	}
	else
	{
		while (flag->width > 0)
		{
			ft_putchar_print(' ', counter);
			flag->width--;
		}
		if (flag->hash)
			prefix_x(flag, counter);
	}
}

void	precision_hex(t_flags *flag, unsigned int data, int *counter,
		void (*f)(unsigned int, int *))
{
	flag->precision -= get_hex_len(data);
	while (flag->precision > 0)
	{
		ft_putchar_print('0', counter);
		flag->precision--;
	}
	f(data, counter);
}

static void	flag_x_suite(t_flags *flag, unsigned int data, int *counter)
{
	if (flag->width > 0)
	{
		if (flag->minus)
		{
			if (!flag->zero && flag->hash && data != 0)
				prefix_x(flag, counter);
			precision_hex(flag, data, counter, ft_putexa_x);
			pading_char_x(flag, counter);
		}
		else
		{
			pading_char_x(flag, counter);
			precision_hex(flag, data, counter, ft_putexa_x);
		}
	}
	else
	{
		if (flag->hash && data != 0)
			prefix_x(flag, counter);
		precision_hex(flag, data, counter, ft_putexa_x);
	}
}

void	flag_x(t_flags *flag, unsigned int data, int *counter)
{
	if (flag->dot && flag->precision == 0 && data == 0)
	{
		while (flag->width-- > 0)
			ft_putchar_print(' ', counter);
		return ;
	}
	if (data == 0)
		flag->hash = 0;
	if (flag->hash && data != 0)
		flag->width -= 2;
	flag->width -= get_hex_len(data);
	if (flag->precision > get_hex_len(data))
		flag->width -= (flag->precision - get_hex_len(data));
	flag_x_suite(flag, data, counter);
}
