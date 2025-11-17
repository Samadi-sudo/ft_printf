/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:05:28 by abantari          #+#    #+#             */
/*   Updated: 2025/11/13 14:05:29 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_pf(char **nptr)
{
	int	result;

	result = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		result = (result * 10) + (**nptr - '0');
		(*nptr)++;
	}
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			i;
	char			*first;

	if (!s)
		return (NULL);
	i = 0;
	first = (char *)s;
	uc = (unsigned char)c;
	while (first[i] && first[i] != uc)
		i++;
	if (first[i] == uc)
		return (&first[i]);
	return (NULL);
}

int	ft_isdigit(char a)
{
	return (a >= '0' && a <= '9');
}

int	countdigits(int n)
{
	long	x;
	int		count;

	x = n;
	if (x == 0)
		return (1);
	if (x < 0)
		x = -x;
	count = 0;
	while (x > 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}
