/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:39:43 by abantari          #+#    #+#             */
/*   Updated: 2025/11/16 16:39:44 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prefix_x(t_flags *flag, int *counter)
{
	if (flag->hash)
	{
		ft_putchar_print('0', counter);
		ft_putchar_print('X', counter);
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

static void	flag_x_suite(t_flags *flag, unsigned int data, int *counter)
{
	if (flag->width > 0)
	{
		if (flag->minus)
		{
			if (!flag->zero && flag->hash && data != 0)
				prefix_x(flag, counter);
			precision_hex(flag, data, counter, ft_putexa_xx);
			pading_char_x(flag, counter);
		}
		else
		{
			pading_char_x(flag, counter);
			precision_hex(flag, data, counter, ft_putexa_xx);
		}
	}
	else
	{
		if (flag->hash && data != 0)
			prefix_x(flag, counter);
		precision_hex(flag, data, counter, ft_putexa_xx);
	}
}

void	flag_xx(t_flags *flag, unsigned int data, int *counter)
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
