/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:03:40 by abantari          #+#    #+#             */
/*   Updated: 2025/11/11 15:03:41 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_print(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putstr_print(char *c, int *counter)
{
	if (!c)
	{
		*counter += write(1, "(null)", 6);
		return ;
	}
	while (*c)
	{
		ft_putchar_print(*c, counter);
		c++;
	}
}
