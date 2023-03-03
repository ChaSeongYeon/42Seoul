/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:25:22 by seocha            #+#    #+#             */
/*   Updated: 2023/02/23 16:41:57 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	player_loc(t_game *game, int i, int j)
{
	game->player.x = i;
	game->player.y = j;
	game->player.loc = j * game->map.width + i;
}

int	line_check(char *line)
{
	if ((ft_strchr(line, '\n')))
		return (ft_strlen(line) - 1);
	else
		return (ft_strlen(line));
}

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
