/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:11:41 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 17:05:14 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	if (dst <= src)
	{
		temp = (char *)dst;
		s = (const char *)src;
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp = (char *)dst;
		temp += len;
		s = (const char *)src;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}
