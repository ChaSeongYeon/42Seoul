/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:38:51 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 17:05:17 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_nbr_len(long long int nbr)
{
	size_t			nbr_len;

	nbr_len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		nbr_len++;
	}
	while (nbr >= 10)
	{
		nbr_len++;
		nbr /= 10;
	}
	return (++nbr_len);
}

char	*ft_itoa(int n)
{
	long long int	nb;
	unsigned int	nbr_len;
	char			*arr;

	nb = n;
	nbr_len = ft_nbr_len(n);
	arr = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!arr)
		return (NULL);
	arr[nbr_len--] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		nb *= -1;
	}
	if (n == 0)
		arr[nbr_len] = '0';
	while (nb > 0)
	{
		arr[nbr_len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (arr);
}
