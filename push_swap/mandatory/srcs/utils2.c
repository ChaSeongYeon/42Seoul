/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:18:25 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 14:45:17 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		cnt++;
		s++;
	}
	return (cnt);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < src_len && (i < dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_len);
}

static int	ft_cnt_split(const char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
		{
			cnt++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (cnt);
}

static char	*ft_arr(const char *str)
{
	int		cnt;
	char	*word;

	cnt = 0;
	while (str[cnt] && !ft_isspace(str[cnt]))
		cnt++;
	word = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, cnt + 1);
	return (word);
}

char	**ft_split(char const *s, int *i)
{
	char	**arr;

	if (*s == '\0')
		exit_error();
	arr = (char **)malloc(sizeof(char *) * (ft_cnt_split(s) + 1));
	if (!s || !arr)
		return (NULL);
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s == '\0')
			break ;
		arr[*i] = ft_arr(s);
		if (arr[*i] == NULL)
		{
			free_split(arr, *i);
			return (NULL);
		}
		(*i)++;
		while (*s && !ft_isspace(*s))
			s++;
	}
	arr[*i] = 0;
	return (arr);
}
