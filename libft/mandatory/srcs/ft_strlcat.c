/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:24:22 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 17:05:06 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_size;

	i = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	dest_size = i;
	j = 0;
	if (dstsize > i)
	{
		while (src[j] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	if (dest_size < dstsize)
		return (dest_size + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}
