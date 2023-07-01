/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:05:42 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/01 19:02:46 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib.h"

int mouse_zoom(int key, t_mlx *param)
{
	int	x;
	int	y;
	
	x = 1;
	y = 1;
	if (key == 4 && x)
	{
		param->fract->min_r -= param->fract->min_r * 0.115;
		param->fract->max_r -= param->fract->max_r * 0.115;
		param->fract->min_i -= param->fract->min_i * 0.115;
		param->fract->max_i -= param->fract->max_i * 0.115;
	}
	else if (key == 5 && y)
	{
		param->fract->min_r += param->fract->min_r * 0.115;
		param->fract->max_r += param->fract->max_r * 0.115;
		param->fract->min_i += param->fract->min_i * 0.115;
		param->fract->max_i += param->fract->max_i * 0.115;
	}
	return (1);
}

