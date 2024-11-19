/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:30:58 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/15 16:54:30 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long n)
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

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	long	temp;

	temp = n;
	len = numlen(temp);
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		temp *= -1;
		nbr[0] = '-';
	}
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
