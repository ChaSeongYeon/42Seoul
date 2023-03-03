/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:20:11 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 17:05:08 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
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
	new_src[i] = '\0';
	return (new_src);
}
