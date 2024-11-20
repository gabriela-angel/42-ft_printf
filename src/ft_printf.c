/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:21:33 by gangel-a          #+#    #+#             */
/*   Updated: 2024/11/19 21:53:57 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//func to handle the va list
#include "ft_printf.h"

static int	handle_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_printchar((char)va_args(args, int));
	else if (format == 's')
		len = ft_printstr(va_args(args, char *));
	else if (format == 'p')
		len = ft_printptr((unsigned long)va_args(args, void *));
	else if (format == 'd' || format == 'i')
		len = ft_printnbr(va_args(args, int));
	else if (format == 'u')
		//len = ft_putchar(va_args(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_printhex(va_args(args, unsigned int), format);
	else if (format == '%')
		len = ft_printchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		out_len;
	va_list	args;

	i = -1;
	out_len = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			out_len += handle_format(args, format[i]);
		}
		else
			out_len += ft_printchar(&format[i]);
	}
	va_end(args);
	return (out_len);
}
