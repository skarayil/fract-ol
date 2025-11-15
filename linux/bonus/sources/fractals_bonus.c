/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:39:28 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/13 11:44:43 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static double	ft_abs(double x)
{
	if (x < 0.0)
		return (-x);
	return (x);
}

static double	ft_log(double x)
{
	double	e;
	double	y;
	double	t;
	double	t2;

	e = 2.718281828459045;
	if (x <= 0.0)
		return (0.0);
	y = 0.0;
	while (x > e)
	{
		x /= e;
		y += 1.0;
	}
	while (x < 1.0)
	{
		x *= e;
		y -= 1.0;
	}
	t = (x - 1.0) / (x + 1.0);
	t2 = t * t;
	y += 2.0 * (t + t2 * t / 3.0 + t2 * t2 * t / 5.0);
	return (y);
}

static void	ft_iterate(t_complex *z, t_complex c, t_fractal_type type)
{
	double	zr2;
	double	zi2;

	zr2 = z->real * z->real;
	zi2 = z->imag * z->imag;
	if (type == CELTIC)
	{
		z->imag = 2.0 * z->real * z->imag + c.imag;
		z->real = ft_abs(zr2 - zi2) + c.real;
	}
	else if (type == TRICORN)
	{
		z->imag = -2.0 * z->real * z->imag + c.imag;
		z->real = zr2 - zi2 + c.real;
	}
}

static double	ft_complex(t_complex z, t_complex c, int iter,
		t_fractal_type type)
{
	int		i;
	double	zr2;
	double	zi2;
	double	log;
	double	nu;

	i = 0;
	while (i < iter)
	{
		ft_iterate(&z, c, type);
		zr2 = z.real * z.real;
		zi2 = z.imag * z.imag;
		if (zr2 + zi2 > 4.0)
		{
			log = ft_log(zr2 + zi2) / 2.0;
			nu = ft_log(log / ft_log(2.0)) / ft_log(2.0);
			return ((double)i + 1.0 - nu);
		}
		i++;
	}
	return ((double)i);
}

double	ft_bonus(t_env *f, t_complex c, int iter)
{
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	return (ft_complex(z, c, iter, f->ftype));
}
