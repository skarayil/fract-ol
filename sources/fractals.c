/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:04:13 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/13 21:31:02 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static double	ft_fractal(t_complex z, t_complex c, int iter)
{
	int		i;
	double	zr2;
	double	zi2;
	double	log;
	double	nu;

	i = 0;
	zr2 = z.real * z.real;
	zi2 = z.imag * z.imag;
	while (zr2 + zi2 <= 4.0 && i < iter)
	{
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = zr2 - zi2 + c.real;
		zr2 = z.real * z.real;
		zi2 = z.imag * z.imag;
		i++;
	}
	if (i < iter)
	{
		log = ft_log(zr2 + zi2) / 2.0;
		nu = ft_log(log / ft_log(2.0)) / ft_log(2.0);
		return ((double)i + 1.0 - nu);
	}
	return ((double)i);
}

double	ft_mandelbrot(t_complex c, int iter)
{
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	return (ft_fractal(z, c, iter));
}

double	ft_julia(t_complex z, t_complex c, int iter)
{
	return (ft_fractal(z, c, iter));
}
