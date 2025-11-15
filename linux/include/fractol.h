/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:17:46 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/15 03:29:35 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_W 800
# define WIN_H 600
# define ITER 1000

# include <stdbool.h>

typedef struct s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
}					t_fractal_type;

typedef union u_fractal_data
{
	t_complex		mandelbrot;
	t_complex		julia;
}					t_fractal_data;

typedef struct s_image
{
	void			*frame;
	char			*pixel;
	int				depth;
	int				stride;
	int				format;
}					t_image;

typedef struct s_view
{
	double			org_x;
	double			org_y;
	double			scale;
}					t_view;

typedef struct s_zoom
{
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
}					t_zoom;

typedef struct s_env
{
	void			*mlx;
	void			*win;
	t_image			image;
	t_view			view;
	t_fractal_type	ftype;
	t_fractal_data	fdata;
	int				tint;
	int				iter;
	t_zoom			zoom;
}					t_env;

double				ft_julia(t_complex z, t_complex c, int iter);
double				ft_mandelbrot(t_complex c, int iter);
bool				ft_parser(int ac, char *av[], t_env *f);
bool				ft_atod(const char *str, double *result);
void				ft_render(t_env *f);
void				ft_init_image(t_env *f);
void				ft_destroy_image(t_env *f);
void				ft_zoom(t_env *f, double x, double y, int dir);
int					ft_on_close(t_env *f);
void				ft_setup_hooks(t_env *f);
int					ft_color(double i, int iter, int tint);

#endif