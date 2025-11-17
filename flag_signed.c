/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:57:44 by abantari          #+#    #+#             */
/*   Updated: 2025/11/16 20:57:45 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_sign(int *counter, long *value, t_flags *flag)
{
	if (*value < 0)
	{
		ft_putchar_print('-', counter);
		*value *= -1;
	}
	else if (flag->plus)
		ft_putchar_print('+', counter);
	else if (flag->space)
		ft_putchar_print(' ', counter);
}

static void	print_padding(int *counter, int pad, char c)
{
	while (pad-- > 0)
		ft_putchar_print(c, counter);
}

static int	get_num_len(long value, t_flags *flag)
{
	int	len;

	if (flag->dot && flag->precision == 0 && value == 0)
		return (0);
	len = countdigits(value);
	if (flag->precision > len)
		len = flag->precision;
	return (len);
}

static void	flag_signed_s(t_flags *flag, int *counter, long *value, int *pad)
{
	if (flag->zero && !flag->dot)
		print_sign(counter, value, flag);
	if (flag->zero && !flag->dot)
		print_padding(counter, *pad, '0');
	else
		print_padding(counter, *pad, ' ');
	if (!(flag->zero && !flag->dot))
		print_sign(counter, value, flag);
}

void	flag_signed(t_flags *flag, int n, int *counter)
{
	int		len;
	int		pad;
	long	value;

	value = n;
	len = get_num_len(value, flag);
	pad = flag->width - len;
	if ((value < 0) || flag->plus || flag->space)
		pad -= 1;
	if (!flag->minus)
		flag_signed_s(flag, counter, &value, &pad);
	else
		print_sign(counter, &value, flag);
	print_padding(counter, flag->precision - countdigits(value), '0');
	if (!(flag->dot && flag->precision == 0 && value == 0))
		ft_putnbr_print(value, counter);
	if (flag->minus)
		print_padding(counter, pad, ' ');
}
