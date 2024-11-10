/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:26:52 by adzahrao          #+#    #+#             */
/*   Updated: 2024/11/09 23:28:54 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int i)
{
	int	cw;

	cw = 0;
	if (i == -2147483648)
	{
		cw += write(1, "-2147483648", 11);
		return (cw);
	}
	if (i < 0)
	{
		cw += write(1, "-", 1);
		i = -i;
	}
	if (i > 9)
	{
		cw += print_nbr(i / 10);
		cw += print_nbr(i % 10);
	}
	else
		cw += ft_putchar(i + '0');
	return (cw);
}

int	print_nbr_u(unsigned int i)
{
	int	cw;

	cw = 0;
	if (i <= 9)
		cw += ft_putchar(i + '0');
	else
	{
		cw += print_nbr_u(i / 10);
		cw += ft_putchar((i % 10) + '0');
	}
	return (cw);
}

int	print_x(unsigned int nb, char c)
{
	char	*table_l;
	char	*table_u;
	int		cw;

	cw = 0;
	table_u = "0123456789ABCDEF";
	table_l = "0123456789abcdef";
	if (nb >= 16)
	{
		cw += print_x(nb / 16, c);
	}
	if (c == 'x')
		cw += ft_putchar(table_l[nb % 16]);
	else if (c == 'X')
		cw += ft_putchar(table_u[nb % 16]);
	return (cw);
}

int	print_xp(unsigned long nb)
{
	char	*table_l;
	int		cw;

	cw = 0;
	table_l = "0123456789abcdef";
	if (nb >= 16)
		cw += print_xp(nb / 16);
	cw += ft_putchar(table_l[nb % 16]);
	return (cw);
}

int	print_p(void *p)
{
	unsigned long	address;
	int				cw;

	cw = 0;
	if (!p)
	{
		cw += write(1, "(nil)", 5);
		return (cw);
	}
	address = (unsigned long)p;
	cw += write(1, "0x", 2);
	cw += print_xp(address);
	return (cw);
}
