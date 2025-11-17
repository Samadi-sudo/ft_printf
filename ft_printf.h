/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abantari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:34:07 by abantari          #+#    #+#             */
/*   Updated: 2025/11/10 20:34:11 by abantari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	zero;
	int	width;
	int	precision;
	int	dot;
	int	hash;
	int	plus;
	int	space;
	int	minus;
}		t_flags;

int		ft_printf(const char *ptr, ...);
void	ft_putchar_print(char c, int *counter);
void	ft_putstr_print(char *c, int *counter);
void	ft_putnbr_print(long n, int *counter);
void	ft_putnbr_uprint(unsigned int i, int *counter);
void	ft_putexa_x(unsigned int i, int *counter);
void	ft_putexa_xx(unsigned int i, int *counter);
void	ft_putexa_p(void *p, int *counter);

// flags
void	flag_char(t_flags *flag, int data, int *counter);
void	flag_x(t_flags *flag, unsigned int data, int *counter);
void	flag_xx(t_flags *flag, unsigned int data, int *counter);
void	flag_adress(t_flags *flag, void *data, int *counter);
void	flag_address_suite_suite(t_flags *flag, void *data, int *counter);
void	flag_string(t_flags *flag, char *str, int *counter);
void	flag_signed(t_flags *flag, int value, int *counter);
void	flag_unsigned(t_flags *flag, unsigned int n, int *counter);

// helpers
int		countdigits(int n);
int		ft_strlen(char *s);
int		ft_isdigit(char a);
int		ft_atoi_pf(char **nptr);
char	*ft_strchr(const char *s, int c);
int		get_hex_len(unsigned int n);
int		get_adress_len(size_t n);
void	precision_hex(t_flags *flag, unsigned int data, int *counter,
			void (*f)(unsigned int, int *));
#endif
