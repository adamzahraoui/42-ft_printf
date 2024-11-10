/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:44:03 by adzahrao          #+#    #+#             */
/*   Updated: 2024/11/10 01:07:13 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	res;

	res = write(1, &c, 1);
	if (!res)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	cw;

	cw = 0;
	i = 0;
	if (!str)
		cw += (write(1, "(null)", 6));
	else
	{
		while (str[i] != '\0')
		{
			cw += ft_putchar(str[i]);
			i++;
		}
	}
	return (cw);
}

int	print_print(va_list arg, const char *src, int i)
{
	int	cw;

	cw = 0;
	if (src[i - 1] == '%' && src[i] == 'c')
		cw = ft_putchar(va_arg(arg, int));
	else if (src[i - 1] == '%' && src[i] == 's')
		cw = ft_putstr(va_arg(arg, char *));
	else if (src[i - 1] == '%' && (src[i] == 'd' || src[i] == 'i'))
		cw = print_nbr(va_arg(arg, int));
	else if (src[i - 1] == '%' && src[i] == 'u')
		cw = print_nbr_u(va_arg(arg, unsigned int));
	else if (src[i - 1] == '%' && (src[i] == 'x' || src[i] == 'X'))
		cw = print_x(va_arg(arg, unsigned int), src[i]);
	else if (src[i - 1] == '%' && src[i] == 'p')
		cw = print_p(va_arg(arg, void *));
	else if (src[i - 1] == '%' && src[i] == '%')
		cw = write(1, "%", 1);
	else
		cw = ft_putchar(src[i]);
	return (cw);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;
	int		j;

	if (write(1, "", 0) == -1)
		return (-1);
	if (!s)
		return (-1);
	count = 0;
	va_start(arg, s);
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == '%')
			count += print_print(arg, s, ++j);
		else
			count += ft_putchar(s[j]);
		if (count == -1)
			return (-1);
		j++;
	}
	va_end(arg);
	return (count);
}
