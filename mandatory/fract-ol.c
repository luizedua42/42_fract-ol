/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:50:45 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/03 19:15:46 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib_bonus.h"
#include <unistd.h>

void	init_mlx(t_mlx *mlx)
{
	mlx->p_mlx = mlx_init();
	mlx->p_win = mlx_new_window(mlx->p_mlx, H, W, "fract-ol");
	mlx_do_key_autorepeaton(mlx->p_mlx);
	mlx->p_img = mlx_new_image(mlx->p_mlx, H, W);
	mlx->i_add = mlx_get_data_addr(mlx->p_img, &mlx->bpp, &mlx->size_line, \
			&mlx->endian);
}

int	close_win(t_mlx *param)
{
	mlx_destroy_window(param->p_mlx, param->p_win);
	exit(0);
}

void	create_fract(t_mlx *params, int color, int x, int y)
{
	char	*dest;

	dest = params->i_add + (y * params->size_line + x * (params->bpp / 8));
	*(unsigned int *)dest = color;
}

void	printerror(void)
{
	write(1, "welcome to the psychdelic world of fractals\n", 45);
	write(1, ":Options:\n", 10);
	write(1, "Mandelbrot\n", 12);
	write(1, "Julia\n", 7);
	write(1, "for julia you will need to input te coordinates for the real(re) and imaginary(im) points\n",90);
	write(1, "range: from -2 to 2\n", 20);
	write(1, "e.g:\n", 5);
	write(1, "Julia -0.8 0.256\n",17);
	exit(1);
}
#include <stdio.h>
t_fractol	fractal_check(int count, char **arg)
{
	t_fractol	fract;

	if (count == 2 && ft_strcmp(arg[1], "Mandelbrot") == 0)
	{
		fract.fract = 1;
		mandelbrot_init(&fract);
	}
	else if (count == 4 && ft_strcmp(arg[1], "Julia") == 0)
	{
		fract.fract = 2;
		if (!coord_checker(arg[2]) || !coord_checker(arg[3]))
			printerror();
		julia_init(&fract, ft_atof(arg[2]), ft_atof(arg[3]));
	}
	else
		printerror();
	return (fract);
}
