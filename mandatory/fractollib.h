/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractollib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:51:28 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/01 19:14:08 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLLIB_H
# define FRACTOLLIB_H

//PARAMS DEFINE
# define H 800
# define W 800
# define MAX_ITER 100

//LIBRARIES INCLUDE
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>

//STRUCTS CREATION
typedef struct s_fractol
{
	float		min_r;
	float		max_r;
	float		min_i;
	float		max_i;
	float		k_r;
	float		k_i;
	int			draw;
	float		pi;
	float		pr;
	float		mid_i;
	float		mid_r;
	int			x;
	int			y;
}				t_fractol;

typedef struct s_mlx
{
	void		*p_win;
	void		*p_mlx;
	void		*p_img;
	char		*i_add;
	int			bpp;
	int			size_line;
	int			endian;
	t_fractol	*fract;
}				t_mlx;

//FUNCS DECLARATION
void			mandelbrot_init(t_fractol *frac);
void			init_julia(t_fractol *frac);
int				draw_fracts(t_mlx *mlx);
int				key_press(int kode, t_mlx *param);
void			fractal_init(t_fractol *frac);
void			create_fract(t_mlx *params, int color, int x, int y);
void			mandelbrot(t_mlx *mlx, float cr, float ci);
void			julia(t_mlx *mlx, float cr, float ci);
int				close_win(t_mlx *param);
int				mouse_zoom(int key,int x, int y, t_mlx *param);



#endif