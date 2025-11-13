/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:20:53 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/13 21:24:13 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "mlx.h"
#include <stddef.h>

static void	ft_init_env(t_env *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->image.frame = NULL;
	f->image.pixel = NULL;
	f->iter = MIN_ITER;
	f->blend = true;
	f->tint = 0;
}

static void	ft_init_zoom(t_env *f)
{
	if (f->ftype == CELTIC || f->ftype == TRICORN)
	{
		f->zoom.min_re = -2.0;
		f->zoom.max_re = 2.0;
		f->zoom.min_im = -2.0;
		f->zoom.max_im = 2.0;
	}
	f->view.org_x = (f->zoom.min_re + f->zoom.max_re) / 2.0;
	f->view.org_y = (f->zoom.min_im + f->zoom.max_im) / 2.0;
	f->view.scale = (f->zoom.max_re - f->zoom.min_re) / WIN_W;
}

static bool	ft_init_mlx(t_env *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (false);
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "fract'ol bonus");
	if (!f->win)
		return (false);
	return (true);
}

void	ft_init_image(t_env *f)
{
	f->image.frame = mlx_new_image(f->mlx, WIN_W, WIN_H);
	if (!f->image.frame)
	{
		ft_on_close(f);
	}
	f->image.pixel = mlx_get_data_addr(f->image.frame, &f->image.depth,
			&f->image.stride, &f->image.format);
}

int	main(int ac, char *av[])
{
	t_env	f;

	ft_init_env(&f);
	if (!ft_parser(ac, av, &f))
		return (1);
	ft_init_zoom(&f);
	if (!ft_init_mlx(&f))
		return (1);
	ft_init_image(&f);
	ft_render(&f);
	ft_setup_hooks(&f);
	mlx_loop(f.mlx);
	return (0);
}
