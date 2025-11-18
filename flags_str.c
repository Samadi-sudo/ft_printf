/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:21:30 by abantari          #+#    #+#             */
/*   Updated: 2025/11/16 20:21:31 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_padding(int *counter, int width)
{
	while (width-- > 0)
		ft_putchar_print(' ', counter);
}

void	flag_string_suite(t_flags *flag, int *counter, char *tmp)
{
	int	len;

	len = ft_strlen(tmp);
	if (flag->dot && flag->precision >= 0 && flag->precision < len)
		len = flag->precision;
	flag->width -= len;
	if (!flag->minus)
		str_padding(counter, flag->width);
	if (len > 0)
	{
		write(1, tmp, len);
		*counter += len;
	}
	if (flag->minus)
		str_padding(counter, flag->width);
}

void	flag_string(t_flags *flag, char *str, int *counter)
{
	char	*tmp;

	if (str == NULL)
	{
		if (flag->dot && flag->precision >= 0 && flag->precision < 6)
			tmp = "";
		else
			tmp = "(null)";
	}
	else
		tmp = str;
	flag_string_suite(flag, counter, tmp);
}

