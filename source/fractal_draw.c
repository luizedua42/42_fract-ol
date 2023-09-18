/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:47:04 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/12 15:06:15 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib.h"

int	draw_fracts(t_mlx *mlx)
{
	double	pr;
	double	pi;

	mlx->fract.y = -1;
	while (++mlx->fract.y < H)
	{
		mlx->fract.x = -1;
		while (++mlx->fract.x < W)
		{
			pr = mlx->fract.min_r + mlx->fract.x * (mlx->fract.max_r
					- mlx->fract.min_r) / W;
			pi = mlx->fract.min_i + mlx->fract.y * (mlx->fract.max_i
					- mlx->fract.min_i) / H;
			mlx->fract.pi = pi;
			mlx->fract.pr = pr;
			if (mlx->fract.fract == 1)
				mandelbrot(mlx, mlx->fract.pr, mlx->fract.pi);
			else if (mlx->fract.fract)
				julia(mlx, mlx->fract.pr, mlx->fract.pi);
		}
	}
	mlx_clear_window(mlx->p_mlx, mlx->p_win);
	mlx_put_image_to_window(mlx->p_mlx, mlx->p_win, mlx->p_img, 0, 0);
	return (0);
}
