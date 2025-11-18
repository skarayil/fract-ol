/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:19:12 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/18 16:15:20 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

static void	ft_move(t_env *f, double x, double y)
{
	double	w;
	double	h;

	w = f->zoom.max_re - f->zoom.min_re;
	h = f->zoom.max_im - f->zoom.min_im;
	f->zoom.min_re += x * w;
	f->zoom.max_re += x * w;
	f->zoom.min_im += y * h;
	f->zoom.max_im += y * h;
	f->view.org_x = (f->zoom.min_re + f->zoom.max_re) / 2.0;
	f->view.org_y = (f->zoom.min_im + f->zoom.max_im) / 2.0;
}

static int	ft_on_key(int key, t_env *f)
{
	if (key == KEY_ESC)
		ft_on_close(f);
	else if (key == KEY_LEFT)
		ft_move(f, -0.1, 0);
	else if (key == KEY_RIGHT)
		ft_move(f, 0.1, 0);
	else if (key == KEY_UP)
		ft_move(f, 0, -0.1);
	else if (key == KEY_DOWN)
		ft_move(f, 0, 0.1);
	else if (key == KEY_C)
		f->tint = (f->tint + 1) % 10;
	else
		return (0);
	ft_render(f);
	return (1);
}

static int	ft_on_mouse(int button, int x, int y, t_env *f)
{
	if (button == MOUSE_UP)
		ft_zoom(f, x, y, 1);
	else if (button == MOUSE_DOWN)
		ft_zoom(f, x, y, -1);
	else
		return (0);
	ft_render(f);
	return (1);
}

int	ft_on_close(t_env *f)
{
	ft_destroy_image(f);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

void	ft_setup_hooks(t_env *f)
{
	mlx_hook(f->win, 17, 0, ft_on_close, f);
	mlx_key_hook(f->win, ft_on_key, f);
	mlx_mouse_hook(f->win, ft_on_mouse, f);
}
