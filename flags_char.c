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

static void	pading_char(t_flags *flag, int *counter)
{
	while (flag->width > 0)
	{
		ft_putchar_print(' ', counter);
		flag->width--;
	}
}

void	flag_char(t_flags *flag, int data, int *counter)
{
	flag->width--;
	if (flag->width > 0)
	{
		if (flag->minus)
		{
			ft_putchar_print(data, counter);
			pading_char(flag, counter);
		}
		else
		{
			pading_char(flag, counter);
			ft_putchar_print(data, counter);
		}
	}
	else
		ft_putchar_print(data, counter);
}
