/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:48:39 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/12 19:25:28 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx_point;

	mlx_point.fract = fractal_check(argc, argv);
	init_mlx(&mlx_point);
	mlx_hook(mlx_point.p_win, 17, 0, close_win, &mlx_point);
	mlx_hook(mlx_point.p_win, KeyPress, KeyPressMask, &key_press, &mlx_point);
	mlx_mouse_hook(mlx_point.p_win, &mouse_zoom, &mlx_point);
	mlx_loop_hook(mlx_point.p_mlx, draw_fracts, &mlx_point);
	mlx_loop(mlx_point.p_mlx);
	return (0);
}
