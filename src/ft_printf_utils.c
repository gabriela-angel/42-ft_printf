/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:29:53 by gangel-a          #+#    #+#             */
/*   Updated: 2024/11/21 16:15:55 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	int	len;

	if (!s)
		return (ft_printstr("(null)"));
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}

int	ft_printhex(unsigned long n, char c)
{
	int		len;
	char	*hex;
	char	hex_no;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_printhex(n / 16, c);
	hex_no = hex[n % 16];
	if (c == 'X')
		hex_no = (char)ft_toupper(hex_no);
	len += write(1, &hex_no, 1);
	return (len);
}

int	ft_printptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	len += ft_printhex(ptr, 'x');
	return (len);
}
