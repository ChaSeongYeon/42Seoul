/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:29:37 by seocha            #+#    #+#             */
/*   Updated: 2023/01/16 08:38:25 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*new_src;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	new_src = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_src)
		return (0);
	while (s1[i])
	{
		new_src[i] = s1[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
		dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	ft_strlcpy(arr, s1, s1_len + 1);
	ft_strlcpy(&arr[s1_len], s2, s1_len + s2_len + 1);
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		size;
	char		*arr;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		size++;
	if (size < start || !len)
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s + start, len + 1);
	return (arr);
}
