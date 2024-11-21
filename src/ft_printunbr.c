/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:03:04 by gangel-a          #+#    #+#             */
/*   Updated: 2024/11/21 15:19:23 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	numlen(unsigned int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_utoa(unsigned int n)
{
	char			*nbr;
	int				len;
	unsigned int	temp;

	temp = n;
	len = numlen(temp);
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (temp == 0)
		nbr[0] = 48;
	while (temp > 0)
	{
		nbr[len - 1] = temp % 10 + 48;
		temp = temp / 10;
		len --;
	}
	return (nbr);
}

int	ft_printunbr(unsigned int n)
{
	int		len;
	char	*str;

	str = ft_utoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}
