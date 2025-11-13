/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:20:51 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/06 22:26:24 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define WIN_W 400
# define WIN_H 300
# define MIN_ITER 80
# define MAX_ITER 2000

# include <stdbool.h>

typedef struct s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef enum e_fractal_type
{
	TRICORN,
	CELTIC,
}					t_fractal_type;

typedef union u_fractal_data
{
	t_complex		celtic;
	t_complex		tricorn;
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
	bool			blend;
	t_zoom			zoom;
}					t_env;

double				ft_bonus(t_env *f, t_complex c, int iter);
bool				ft_parser(int ac, char *av[], t_env *f);
void				ft_render(t_env *f);
void				ft_init_image(t_env *f);
void				ft_destroy_image(t_env *f);
void				ft_zoom(t_env *f, double x, double y, int dir);
int					ft_on_close(t_env *f);
void				ft_setup_hooks(t_env *f);
int					ft_color(double i, int iter, int tint);
int					ft_on_close(t_env *f);
void				ft_setup_hooks(t_env *f);

#endif