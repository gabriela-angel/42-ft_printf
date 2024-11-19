/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangel-a <gangel-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:50:06 by gangel-a          #+#    #+#             */
/*   Updated: 2024/10/21 14:27:02 by gangel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	i = 0;
	if (size <= len_d)
		return (size + len_s);
	while (src[i] && len_d + i < size - 1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	if (len_d + i < size)
		dst[len_d + i] = '\0';
	return (len_d + len_s);
}
