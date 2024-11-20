/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:57:26 by gangel-a          #+#    #+#             */
/*   Updated: 2024/11/19 16:36:05 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printnbr(int n);
int	ft_printunbr(unsigned int n);
int	ft_printhex(unsigned long n, char c);
int	ft_printptr(unsigned long ptr);

#endif