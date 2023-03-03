/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:50:19 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 17:04:59 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*arr;

	begin = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (s1[end -1] && ft_strchr(set, s1[end - 1]))
	{
		if (end - 1 < 1)
			break ;
		end--;
	}
	if (begin > end)
		return (ft_strdup(""));
	arr = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1 + begin, end - begin + 1);
	return (arr);
}
