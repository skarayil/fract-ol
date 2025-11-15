/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:01:41 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/15 03:28:22 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_compute(t_env *f, int dir)
{
	double	scale;
	double	width;

	width = f->zoom.max_re - f->zoom.min_re;
	if (dir > 0)
	{
		scale = 0.9;
		if (f->iter < 500)
			f->iter += 5;
	}
	else
	{
		scale = 1.1;
		if (f->iter > ITER && width > 0.1)
			f->iter -= 5;
	}
	return (scale);
}

static void	ft_apply(t_env *f, double x, double y, double zoom)
{
	double	width;
	double	height;
	double	org_re;
	double	org_im;

	width = f->zoom.max_re - f->zoom.min_re;
	org_re = f->zoom.min_re + x * width / WIN_W;
	org_im = f->zoom.min_im + y * (f->zoom.max_im - f->zoom.min_im) / WIN_H;
	f->zoom.min_re = org_re - (x / WIN_W) * width * zoom;
	f->zoom.max_re = f->zoom.min_re + width * zoom;
	height = (f->zoom.max_im - f->zoom.min_im) * zoom;
	f->zoom.min_im = org_im - (y / WIN_H) * height;
	f->zoom.max_im = f->zoom.min_im + height;
}

void	ft_zoom(t_env *f, double x, double y, int dir)
{
	double	zoom;

	if (!f)
		return ;
	zoom = ft_compute(f, dir);
	ft_apply(f, x, y, zoom);
	f->view.org_x = (f->zoom.min_re + f->zoom.max_re) / 2.0;
	f->view.org_y = (f->zoom.min_im + f->zoom.max_im) / 2.0;
	f->view.scale = (f->zoom.max_re - f->zoom.min_re) / WIN_W;
}
