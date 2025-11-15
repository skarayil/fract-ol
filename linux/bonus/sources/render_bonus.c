/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:51:48 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/13 21:25:49 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "mlx.h"
#include <stddef.h>

static t_complex	ft_pixel_to_complex(t_env *f, int x, int y)
{
	t_complex	c;

	c.real = f->zoom.min_re + x * (f->zoom.max_re - f->zoom.min_re) / WIN_W;
	c.imag = f->zoom.min_im + y * (f->zoom.max_im - f->zoom.min_im) / WIN_H;
	return (c);
}

static void	ft_put_pixel(t_image *image, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	dest = image->pixel + (y * image->stride + x * (image->depth / 8));
	*(int *)dest = color;
}

static void	ft_render_pixel(t_env *f, int x, int y)
{
	t_complex	point;
	double		i;
	int			color;

	point = ft_pixel_to_complex(f, x, y);
	if (f->ftype == CELTIC || f->ftype == TRICORN)
		i = ft_bonus(f, point, f->iter);
	else
		i = 0.0;
	color = ft_color(i, f->iter, f->tint);
	ft_put_pixel(&f->image, x, y, color);
}

void	ft_destroy_image(t_env *f)
{
	if (f->image.frame)
	{
		mlx_destroy_image(f->mlx, f->image.frame);
		f->image.frame = NULL;
		f->image.pixel = NULL;
	}
}

void	ft_render(t_env *f)
{
	int	x;
	int	y;

	ft_destroy_image(f);
	ft_init_image(f);
	if (!f || !f->image.frame || !f->image.pixel)
		return ;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			ft_render_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image.frame, 0, 0);
}
