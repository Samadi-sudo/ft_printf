/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:08:32 by abantari          #+#    #+#             */
/*   Updated: 2025/11/16 21:08:33 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_count_digits(unsigned long n)
{
	int	d;

	if (n == 0)
		return (1);
	d = 0;
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

static void	u_padding(int *counter, int width, char pad)
{
	while (width-- > 0)
		ft_putchar_print(pad, counter);
}

void	flag_unsigned_suite(t_flags *flag, unsigned int n, int pads[2],
		int *counter)
{
	if (!flag->minus)
	{
		if (flag->zero && !flag->dot)
			u_padding(counter, pads[1], '0');
		else
			u_padding(counter, pads[1], ' ');
	}
	u_padding(counter, pads[0], '0');
	if (!(flag->dot && flag->precision == 0 && n == 0))
		ft_putnbr_uprint(n, counter);
	if (flag->minus)
		u_padding(counter, pads[1], ' ');
}

void	flag_unsigned(t_flags *flag, unsigned int n, int *counter)
{
	int	len;
	int	pad_zero;
	int	pad_space;
	int	pads[2];

	len = u_count_digits((unsigned long)n);
	if (flag->dot && flag->precision == 0 && n == 0)
		len = 0;
	pad_zero = 0;
	if (flag->dot && flag->precision > len)
		pad_zero = flag->precision - len;
	if (flag->width > len + pad_zero)
		pad_space = flag->width - (len + pad_zero);
	else
		pad_space = 0;
	pads[0] = pad_zero;
	pads[1] = pad_space;
	flag_unsigned_suite(flag, n, pads, counter);
}
