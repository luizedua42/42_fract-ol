/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractollib_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:51:28 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/12 19:24:32 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLLIB_BONUS_H
# define FRACTOLLIB_BONUS_H

//PARAMS DEFINE
# define H 800
# define W 800
# define MAX_ITER 200

//LIBRARIES INCLUDE
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>

//STRUCTS CREATION
typedef struct s_fractol
{
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		k_r;
	double		k_i;
	int			draw;
	double		pi;
	double		pr;
	double		mid_i;
	double		mid_r;
	int			x;
	int			y;
	int			fract;
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
	t_fractol	fract;
	int			colors[3];
	int			c;
}				t_mlx;

//FUNCS DECLARATION
void			mandelbrot_init(t_fractol *frac);
int				draw_fracts(t_mlx *mlx);
int				key_press(int kode, t_mlx *param);
void			fractal_init(t_fractol *frac);
void			create_fract(t_mlx *params, int color, int x, int y);
void			mandelbrot(t_mlx *mlx, double cr, double ci);
void			julia(t_mlx *mlx, double cr, double ci);
int				close_win(t_mlx *param);
int				mouse_zoom(int key, int x, int y, t_mlx *param);
int				ft_strcmp(const char *s1, const char *s2);
t_fractol		fractal_check(int count, char **arg);
void			init_mlx(t_mlx *mlx);
double			ft_atof(char *str);
int				coord_checker(char *str);
void			julia_init(t_fractol *frac, double kr, double ki);
void			printerror(void);
void			init_color(t_mlx *mlx);
double			ft_abs(double n);

#endif