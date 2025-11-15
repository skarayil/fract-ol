/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:29:54 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/06 22:27:54 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

static void	ft_move(t_env *f, double x, double y)
{
	double	win_h;
	double	win_w;

	win_w = (f->zoom.max_re - f->zoom.min_re);
	win_h = (f->zoom.max_im - f->zoom.min_im);
	f->zoom.min_re += x * win_w;
	f->zoom.max_re += x * win_w;
	f->zoom.min_im += y * win_h;
	f->zoom.max_im += y * win_h;
	f->view.org_x = (f->zoom.min_re + f->zoom.max_re) / 2.0;
	f->view.org_y = (f->zoom.min_im + f->zoom.max_im) / 2.0;
}

static int	ft_on_key(int id, t_env *f)
{
	if (id == XK_Escape)
		return (ft_on_close(f), true);
	else if (id == XK_Left)
		ft_move(f, -0.1, 0.0);
	else if (id == XK_Right)
		ft_move(f, 0.1, 0.0);
	else if (id == XK_Up)
		ft_move(f, 0.0, -0.1);
	else if (id == XK_Down)
		ft_move(f, 0.0, 0.1);
	else if (id == XK_c || id == XK_C)
		f->tint = (f->tint + 1) % 10;
	else
		return (false);
	ft_render(f);
	return (true);
}

static int	ft_on_mouse(int id, int x, int y, t_env *f)
{
	if (id == Button4)
		ft_zoom(f, (double)x, (double)y, 1);
	else if (id == Button5)
		ft_zoom(f, (double)x, (double)y, -1);
	else
		return (false);
	ft_render(f);
	return (true);
}

int	ft_on_close(t_env *f)
{
	ft_destroy_image(f);
	if (f->win)
	{
		mlx_destroy_window(f->mlx, f->win);
		f->win = NULL;
	}
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		f->mlx = NULL;
	}
	exit(0);
	return (0);
}

void	ft_setup_hooks(t_env *f)
{
	mlx_hook(f->win, 17, 0, ft_on_close, f);
	mlx_key_hook(f->win, ft_on_key, f);
	mlx_mouse_hook(f->win, ft_on_mouse, f);
}
