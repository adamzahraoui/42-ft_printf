/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:36:24 by adzahrao          #+#    #+#             */
/*   Updated: 2024/11/09 23:31:09 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	print_print(va_list arg, const char *src, int i);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	print_nbr(int i);
int	print_nbr_u(unsigned int i);
int	print_x(unsigned int a, char c);
int	print_p(void *ptr);
int	print_xp(unsigned long nb);

#endif