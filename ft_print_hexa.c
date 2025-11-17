/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:10:29 by abantari          #+#    #+#             */
/*   Updated: 2025/11/12 18:10:30 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putexa_x(unsigned int i, int *counter)
{
	char	*t;

	t = "0123456789abcdef";
	if (i >= 16)
		ft_putexa_x(i / 16, counter);
	ft_putchar_print(t[i % 16], counter);
}

void	ft_putexa_xx(unsigned int i, int *counter)
{
	char	*t;

	t = "0123456789ABCDEF";
	if (i >= 16)
		ft_putexa_xx(i / 16, counter);
	ft_putchar_print(t[i % 16], counter);
}

static void	ft_putexa_address(size_t i, int *counter)
{
	char	*t;

	t = "0123456789abcdef";
	if (i >= 16)
		ft_putexa_address(i / 16, counter);
	ft_putchar_print(t[i % 16], counter);
}

void	ft_putexa_p(void *p, int *counter)
{
	ft_putexa_address((size_t)p, counter);
}
