/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:24:48 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/01 18:17:35 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib.h"

void	key_zoom(int key, t_mlx *param)
{
	if (key == 'z')
	{
		param->fract->min_r -= param->fract->min_r * 0.115;
		param->fract->max_r -= param->fract->max_r * 0.115;
		param->fract->min_i -= param->fract->min_i * 0.115;
		param->fract->max_i -= param->fract->max_i * 0.115;
	}
	else if (key == 'x')
	{
		param->fract->min_r += param->fract->min_r * 0.115;
		param->fract->max_r += param->fract->max_r * 0.115;
		param->fract->min_i += param->fract->min_i * 0.115;
		param->fract->max_i += param->fract->max_i * 0.115;
	}
}

void	move_fract(int key, t_mlx *mlx)
{
	mlx->fract->mid_i = mlx->fract->max_i - mlx->fract->min_i;
	mlx->fract->mid_r = mlx->fract->max_r - mlx->fract->min_r;
	if (key == XK_Up)
	{
		mlx->fract->max_i -= mlx->fract->mid_i * 0.125;
		mlx->fract->min_i -= mlx->fract->mid_i * 0.125;
	}
	else if (key == XK_Down)
	{
		mlx->fract->max_i += mlx->fract->mid_i * 0.125;
		mlx->fract->min_i += mlx->fract->mid_i * 0.125;
	}
	else if (key == XK_Left)
	{
		mlx->fract->min_r -= mlx->fract->mid_r * 0.125;
		mlx->fract->max_r -= mlx->fract->mid_r * 0.125;
	}
	else if (key == XK_Right)
	{
		mlx->fract->min_r += mlx->fract->mid_r * 0.125;
		mlx->fract->max_r += mlx->fract->mid_r * 0.125;
	}
}

int	key_press(int kode, t_mlx *param)
{
	if (kode == XK_Escape)
		close_win(param);
	else if (kode == 'z' || kode == 'x')
		key_zoom(kode, param);
	else if (kode == XK_Up || kode == XK_Down || \
				kode == XK_Left || kode == XK_Right)
		move_fract(kode, param);
	else if(kode == 4 || kode == 5)
		mouse_zoom(kode, param);
	draw_fracts(param);
	return (0);
}
