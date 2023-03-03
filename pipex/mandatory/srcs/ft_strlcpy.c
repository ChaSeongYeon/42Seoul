/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:48:45 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:47:07 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	quote(const char *src, size_t *i, size_t *dstsize, size_t *flag)
{
	if (src[*i] == '\'' && !(*flag))
	{
		*i = *i + 1;
		*dstsize = *dstsize - 1;
		*flag = 1;
	}
	if (src[*i] == '\"' && !(*flag))
	{
		*i = *i + 1;
		*dstsize = *dstsize - 1;
		*flag = 1;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	flag;
	size_t	src_len;

	i = 0;
	j = 0;
	flag = 0;
	src_len = ft_strlen(src);
	while (i < src_len && (i < dstsize - 1) && dstsize != 0)
	{
		quote(src, &i, &dstsize, &flag);
		dst[j++] = src[i++];
	}
	if (dstsize > 0)
		dst[j] = '\0';
	return (src_len);
}
