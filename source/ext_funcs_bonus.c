/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_funcs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:32:33 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/12 19:34:05 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	return (0);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;
	int		deccount;

	res = 0;
	sign = 1;
	deccount = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		deccount = deccount * 10;
		str++;
	}
	return (res = res / deccount * sign);
}

int	coord_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	init_color(t_mlx *mlx)
{
	mlx->c = 0;
	mlx->colors[0] = 0x010000;
	mlx->colors[1] = 65537;
	mlx->colors[2] = 773;
}

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
