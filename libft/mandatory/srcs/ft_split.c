/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:17 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 17:05:10 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_cnt_split(const char *str, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			cnt ++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*ft_arr(const char *str, char c)
{
	int		cnt;
	char	*word;

	cnt = 0;
	while (str[cnt] && !(str[cnt] == c))
		cnt++;
	word = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, cnt + 1);
	return (word);
}

void	free_split(char **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_cnt_split(s, c) + 1));
	if (!s || !arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		arr[i] = ft_arr(s, c);
		if (arr[i] == NULL)
		{
			free_split(arr, i);
			return (NULL);
		}
		i++;
		while (*s && *s != c)
			s++;
	}
	arr[i] = 0;
	return (arr);
}
