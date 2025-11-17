/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_adress_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:04:05 by abantari          #+#    #+#             */
/*   Updated: 2025/11/16 19:04:06 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prefix_x(t_flags *flag, int *counter)
{
	if (flag->plus)
		ft_putchar_print('+', counter);
	else if (flag->space)
		ft_putchar_print(' ', counter);
}

static void	pading_char_x(t_flags *flag, int *counter)
{
	if (flag->zero && !flag->dot)
	{
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
	}
}

static void	precision_adress(t_flags *flag, void *data, int *counter,
		void (*f)(void *, int *))
{
	flag->precision -= get_adress_len((size_t)data);
	while (flag->precision > 0)
	{
		ft_putchar_print('0', counter);
		flag->precision--;
	}
	f(data, counter);
}

void	flag_address_suite_suite(t_flags *flag, void *data, int *counter)
{
	if (flag->zero && !flag->dot)
	{
		if (flag->plus || flag->space)
			prefix_x(flag, counter);
		ft_putchar_print('0', counter);
		ft_putchar_print('x', counter);
		pading_char_x(flag, counter);
		precision_adress(flag, data, counter, ft_putexa_p);
	}
	else
	{
		pading_char_x(flag, counter);
		if (flag->plus || flag->space)
			prefix_x(flag, counter);
		ft_putchar_print('0', counter);
		ft_putchar_print('x', counter);
		precision_adress(flag, data, counter, ft_putexa_p);
	}
}
