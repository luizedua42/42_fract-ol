/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fracs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:57:37 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/12 19:36:50 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib_bonus.h"

void	tri_init(t_fractol *frac)
{
	frac->min_r = -2.0;
	frac->max_r = 1.0;
	frac->min_i = -1.5;
	frac->max_i = frac->min_i + (frac->max_r - frac->min_r) * H / W;
}

void	tricorn(t_mlx *mlx, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	temp;

	zr = 0;
	zi = 0;
	n = -1;
	while (++n < MAX_ITER && ((zr * zr) + (zi * zi) <= 4))
	{
		temp = -2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
	}
	if (n == MAX_ITER)
		create_fract(mlx, 0x0, mlx->fract.x, mlx->fract.y);
	else
		create_fract(mlx, mlx->colors[mlx->c] * n, mlx->fract.x, \
			mlx->fract.y);
}
