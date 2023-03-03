/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:06:36 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:42:58 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	if (!s)
		return (-1);
	while (*s != '\0')
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	*ft_strdup_xn(const char *s1)
{
	int		i;
	int		len;
	char	*new_src;

	i = 0;
	len = ft_strlen(s1);
	new_src = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_src)
		return (0);
	while (s1[i])
	{
		new_src[i] = s1[i];
		i++;
	}
	if (new_src[i - 1] == '\n')
		new_src[i - 1] = '\0';
	else
		new_src[i] = '\0';
	return (new_src);
}

static size_t	ft_strlcpy_xn(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (i < src_len && (i < dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		if (dst[i - 1] == '\n')
			dst[i - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strjoin_xn(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*arr;

	if (!s1)
		return (0);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy_xn(arr, s1, s1_len + 1);
	ft_strlcpy_xn(&arr[s1_len], s2, s1_len + s2_len + 1);
	return (arr);
}
