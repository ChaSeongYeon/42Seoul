/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:17 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:47:08 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ft_cnt_split(const char *str, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		cnt++;
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			if (str[i] == '\'')
				while (str[i] && str[i + 1] != '\'')
					i++;
			else if (str[i] == '\"')
				while (str[i] && str[i + 1] != '\"')
					i++;
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
	if (str[cnt] && str[cnt] == '\'')
		while (str[cnt] && str[cnt + 1] != '\'')
			cnt++;
	else if (str[cnt] && str[cnt] == '\"')
		while (str[cnt] && str[cnt + 1] != '\"')
			cnt++;
	while (str[cnt] && str[cnt] != c)
		cnt++;
	word = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, cnt + 1);
	return (word);
}

static void	free_split(char **arr, int idx)
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

static void	ft_split2(char const **s, char c)
{
	if (*(s[0]) == '\'')
		while (*(s[0]) && (*(s[0]) + 1) != '\'')
			s[0]++;
	else if (*(s[0]) == '\"')
		while (*(s[0]) && (*(s[0]) + 1) != '\"')
			s[0]++;
	while (*(s[0]) && *(s[0]) != c)
		s[0]++;
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
		ft_split2(&s, c);
	}
	arr[i] = 0;
	return (arr);
}
