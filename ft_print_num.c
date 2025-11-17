/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:31:45 by abantari          #+#    #+#             */
/*   Updated: 2025/11/12 16:31:46 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_print(long n, int *counter)
{
	if (n < 0)
	{
		ft_putchar_print('-', counter);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_print(n / 10, counter);
	ft_putchar_print((n % 10) + '0', counter);
}

void	ft_putnbr_uprint(unsigned int i, int *counter)
{
	unsigned int	n;

	n = i;
	if (n >= 10)
		ft_putnbr_uprint(n / 10, counter);
	ft_putchar_print((n % 10) + '0', counter);
}
