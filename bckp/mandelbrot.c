/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:57:37 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/01 16:33:25 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib.h"

void	mandelbrot_init(t_fractol *frac)
{
	frac->min_r = -2.0;
	frac->max_r = 1.0;
	frac->min_i = -1.5;
	frac->max_i = frac->min_i + (frac->max_r - frac->min_r) * H / W;
}

void	mandelbrot(t_mlx *mlx, float cr, float ci)
{
	int		n;
	float	zr;
	float	zi;
	float	temp;

	zr = 0;
	zi = 0;
	n = -1;
	while (++n < MAX_ITER && ((zr * zr) + (zi * zi) <= 4))
	{
		temp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
	}
	if (n == MAX_ITER)
		create_fract(mlx, 0x0, mlx->fract->x, mlx->fract->y);
	else
		create_fract(mlx, 0x00ff00 * zi, mlx->fract->x, mlx->fract->y);
}

int	draw_fracts(t_mlx *mlx)
{
	float	pr;
	float	pi;

	mlx->fract->y = -1;
	while (++mlx->fract->y < H)
	{
		mlx->fract->x = -1;
		while (++mlx->fract->x < W)
		{
			pr = mlx->fract->min_r + mlx->fract->x * (mlx->fract->max_r
					- mlx->fract->min_r) / W;
			pi = mlx->fract->min_i + mlx->fract->y * (mlx->fract->max_i
					- mlx->fract->min_i) / H;
			mlx->fract->pi = pi;
			mlx->fract->pr = pr;
			julia(mlx, mlx->fract->pr, mlx->fract->pi);
		}
	}
	mlx_put_image_to_window(mlx->p_mlx, mlx->p_win, mlx->p_img, 0, 0);
	return (0);
}
