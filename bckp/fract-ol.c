/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:50:45 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/01 16:34:31 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->p_mlx = mlx_init();
	mlx->p_win = mlx_new_window(mlx->p_mlx, H, W, "fract-ol");
	mlx_do_key_autorepeaton(mlx->p_mlx);
	mlx->p_img = mlx_new_image(mlx->p_mlx, H, W);
	mlx->i_add = mlx_get_data_addr(mlx->p_img, &mlx->bpp, &mlx->size_line,
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

int	main(void)
{
	t_mlx	mlx_point;

	init_mlx(&mlx_point);
	mlx_hook(mlx_point.p_win, 17, 0, close_win, &mlx_point);
	mlx_hook(mlx_point.p_win, KeyPress, KeyPressMask, &key_press, &mlx_point);
	init_julia(mlx_point.fract);
	draw_fracts(&mlx_point);
	mlx_loop(mlx_point.p_mlx);
	return (0);
}
