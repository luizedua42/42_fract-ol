/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:05:42 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/12 19:41:25 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib_bonus.h"

void	move_mouse(int x, int y, t_mlx *param)
{
	x -= W / 2;
	y -= H / 2;
	param->fract.mid_i = param->fract.max_i - param->fract.min_i;
	param->fract.mid_r = param->fract.max_r - param->fract.min_r;
	if (y < 0)
	{
		param->fract.max_i -= param->fract.mid_i * ((ft_abs(y) / H) * 0.5);
		param->fract.min_i -= param->fract.mid_i * ((ft_abs(y) / H) * 0.5);
	}
	else if (y > 0)
	{
		param->fract.max_i += param->fract.mid_i * ((ft_abs(y) / H) * 0.5);
		param->fract.min_i += param->fract.mid_i * ((ft_abs(y) / H) * 0.5);
	}
	if (x < 0)
	{
		param->fract.min_r -= param->fract.mid_r * ((ft_abs(x) / W) * 0.5);
		param->fract.max_r -= param->fract.mid_r * ((ft_abs(x) / W) * 0.5);
	}
	else if (x > 0)
	{
		param->fract.min_r += param->fract.mid_r * ((ft_abs(x) / W) * 0.5);
		param->fract.max_r += param->fract.mid_r * ((ft_abs(x) / W) * 0.5);
	}
}

int	mouse_zoom(int key, int x, int y, t_mlx *param)
{
	param->fract.mid_i = param->fract.max_i - param->fract.min_i;
	param->fract.mid_r = param->fract.max_r - param->fract.min_r;
	if (key == 4)
	{
		param->fract.min_r += param->fract.mid_r * 0.115;
		param->fract.max_r -= param->fract.mid_r * 0.115;
		param->fract.min_i += param->fract.mid_i * 0.115;
		param->fract.max_i -= param->fract.mid_i * 0.115;
		move_mouse(x, y, param);
	}
	else if (key == 5)
	{
		param->fract.min_r -= param->fract.mid_r * 0.115;
		param->fract.max_r += param->fract.mid_r * 0.115;
		param->fract.min_i -= param->fract.mid_i * 0.115;
		param->fract.max_i += param->fract.mid_i * 0.115;
		move_mouse(x, y, param);
	}
	return (1);
}
