/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:28:10 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/03 19:15:46 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib_bonus.h"

void	julia_init(t_fractol *frac, float kr, float ki)
{
	if ((kr < -2 || kr > 2) || (ki < -2 || ki > 2))
		printerror();
	frac->min_r = -2.0;
	frac->max_r = 2.0;
	frac->min_i = -2.0;
	frac->max_i = frac->min_i + (frac->max_r - frac->min_r) * H / W;	
	frac->k_i = ki;
	frac->k_r = kr;
}

void	julia(t_mlx *mlx, float cr, float ci)
{
	int		n;
	float	tmp;

	n = -1;
	while (++n < MAX_ITER)
	{
		if ((cr * cr + ci * ci) > 4.0)
			break ;
		tmp = 2 * cr * ci - mlx->fract.k_i;
		cr = cr * cr - ci * ci + mlx->fract.k_r;
		ci = tmp;
	}
	if (n == MAX_ITER)
		create_fract(mlx, 0x0, mlx->fract.x, mlx->fract.y);
	else
		create_fract(mlx, 0xff11fa * n , mlx->fract.x, \
				mlx->fract.y);
}
