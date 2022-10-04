/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:57:38 by psydenst          #+#    #+#             */
/*   Updated: 2022/09/28 18:16:42 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_arg(const char *format, int i, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += ft_print_arg(format, i, ap);
			i++;
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}

int	ft_print_arg(const char *format, int i, va_list ap)
{
	if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'p')
		return (ft_print_ptr(va_arg(ap, void *), format[i + 1]));
	else if (format[i + 1] == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_put_unsig_nbr(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'X')
		return (ft_print_hexa(va_arg(ap, unsigned int), format[i + 1]));
	else if (format[i + 1] == 'x')
		return (ft_print_hexa(va_arg(ap, unsigned int), format[i + 1]));
	else
		return (0);
}
