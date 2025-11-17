/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:19:08 by abantari          #+#    #+#             */
/*   Updated: 2025/11/16 17:19:10 by abantari         ###   ########.fr       */
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
	if (flag->zero && !flag->dot && !flag->minus)
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

static void	flag_address_suite(t_flags *flag, void *data, int *counter)
{
	if (flag->width > 0)
	{
		if (flag->minus)
		{
			if (flag->plus || flag->space)
				prefix_x(flag, counter);
			ft_putchar_print('0', counter);
			ft_putchar_print('x', counter);
			precision_adress(flag, data, counter, ft_putexa_p);
			pading_char_x(flag, counter);
		}
		else
			flag_address_suite_suite(flag, data, counter);
	}
	else
	{
		if (flag->plus || flag->space)
			prefix_x(flag, counter);
		ft_putchar_print('0', counter);
		ft_putchar_print('x', counter);
		precision_adress(flag, data, counter, ft_putexa_p);
	}
}

void	flag_adress(t_flags *flag, void *data, int *counter)
{
	if (!data)
	{
		ft_putstr_print("(nil)", counter);
		return ;
	}
	if (flag->dot && flag->precision == 0 && data == 0)
	{
		while (flag->width-- > 0)
			ft_putchar_print(' ', counter);
		return ;
	}
	flag->width -= 2;
	if (flag->plus || flag->space)
		flag->width--;
	flag->width -= get_adress_len((size_t)data);
	if (flag->precision > get_adress_len((size_t)data))
		flag->width -= (flag->precision - get_adress_len((size_t)data));
	flag_address_suite(flag, data, counter);
}
